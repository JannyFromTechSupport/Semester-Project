// SweetHertz — Flora Farms Greenhouse Monitor
// ICS 4111 Semester Project: Deliverable 3
// Base: https://docs.wokwi.com/guides/esp32-wifi

#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>

// ── LCD (confirmed-working init style) ──────────────────────────────────────
LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

// ── WiFi ────────────────────────────────────────────────────────────────────
#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASS ""

// ── InfluxDB ────────────────────────────────────────────────────────────────
#define INFLUXDB_URL    "https://us-east-1-1.aws.cloud2.influxdata.com"
#define INFLUXDB_TOKEN  "MgHgUaLCE5rfYJ_WRYGikLjHG-Dbj0BSmWoBL-db_quRFt2bRla1-tXp09_ZWwjr6iiNE9w0faEu_VX9SUDO7A=="
#define INFLUXDB_ORG    "ca70190bc3f80c2d"
#define INFLUXDB_BUCKET "greenhouse"
#define TZ_INFO         "EAT-3"

// ── Sensors ─────────────────────────────────────────────────────────────────
#define DHT_PIN  15
#define DHT_TYPE DHT22
#define MQ5_PIN  34

DHT dht(DHT_PIN, DHT_TYPE);

InfluxDBClient influxClient(
  INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN,
  InfluxDbCloud2CACert
);
Point sensorPoint("greenhouse_sensors");

// ── WiFi spinner (from working starter) ─────────────────────────────────────
void spinner() {
  static int8_t counter = 0;
  const char* glyphs = "\xa1\xa5\xdb";
  LCD.setCursor(15, 1);
  LCD.print(glyphs[counter++]);
  if (counter == strlen(glyphs)) counter = 0;
}

// ── Setup ────────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(115200);

  // LCD — confirmed-working init sequence
  LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("Connecting to");
  LCD.setCursor(0, 1);
  LCD.print("WiFi ");

  // WiFi — channel 6 required for Wokwi-GUEST
  WiFi.begin(WIFI_SSID, WIFI_PASS, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    spinner();
  }

  Serial.println("WiFi connected");
  Serial.print("IP: "); Serial.println(WiFi.localIP());

  LCD.clear();
  LCD.setCursor(0, 0); LCD.print("SweetHertz IoT");
  LCD.setCursor(0, 1); LCD.print("WiFi OK!");
  delay(1500);

  // NTP time sync (required for InfluxDB timestamps)
  LCD.clear();
  LCD.setCursor(0, 0); LCD.print("Syncing time");
  LCD.setCursor(0, 1); LCD.print("NTP...");
  timeSync(TZ_INFO, "pool.ntp.org", "time.nist.gov");
  Serial.println("Time synced");

  // InfluxDB
  if (influxClient.validateConnection()) {
    Serial.println("InfluxDB OK");
    LCD.clear();
    LCD.setCursor(0, 0); LCD.print("InfluxDB OK");
    LCD.setCursor(0, 1); LCD.print("Cloud ready");
  } else {
    Serial.print("InfluxDB FAILED: ");
    Serial.println(influxClient.getLastErrorMessage());
    LCD.clear();
    LCD.setCursor(0, 0); LCD.print("InfluxDB FAIL");
    LCD.setCursor(0, 1); LCD.print("Check token");
  }
  delay(1500);

  dht.begin();
  sensorPoint.addTag("device",   "esp32-flora-farms");
  sensorPoint.addTag("location", "naivasha-greenhouse");
}

// ── Loop ─────────────────────────────────────────────────────────────────────
void loop() {
  static unsigned long lastSend = 0;

  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  int   gas  = analogRead(MQ5_PIN);
  float gasV = gas * (3.3f / 4095.0f);

  if (isnan(temp) || isnan(hum)) {
    Serial.println("DHT22 read failed");
    LCD.clear();
    LCD.setCursor(0, 0); LCD.print("Sensor Error!");
    LCD.setCursor(0, 1); LCD.print("Check DHT22");
    delay(2000);
    return;
  }

  // Serial output
  Serial.print("T:"); Serial.print(temp, 1);
  Serial.print("C H:"); Serial.print(hum, 0);
  Serial.print("% Gas:"); Serial.println(gas);

  // LCD display
  char l1[17], l2[17];
  snprintf(l1, sizeof(l1), "T:%.1fC H:%.0f%%", temp, hum);
  snprintf(l2, sizeof(l2), "Gas:%4d %.2fV",    gas,  gasV);
  LCD.clear();
  LCD.setCursor(0, 0); LCD.print(l1);
  LCD.setCursor(0, 1); LCD.print(l2);

  // InfluxDB — write every 10 s
  if (millis() - lastSend >= 10000) {
    lastSend = millis();
    if (WiFi.status() == WL_CONNECTED) {
      sensorPoint.clearFields();
      sensorPoint.addField("temperature", temp);
      sensorPoint.addField("humidity",    hum);
      sensorPoint.addField("gas_raw",     gas);
      sensorPoint.addField("gas_voltage", gasV);
      if (!influxClient.writePoint(sensorPoint)) {
        Serial.print("Write failed: ");
        Serial.println(influxClient.getLastErrorMessage());
      } else {
        Serial.println("InfluxDB write OK");
      }
    }
  }

  delay(2000);
}
