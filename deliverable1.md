# ICS 4111: Embedded Systems & IoT 
## Semester Project: Deliverable 1 

**Group Name:** SweetHertz 

| Student                  | Admission No.           |
|--------------------------|-------------------------|
| Njogorio Sharon Nyambura | 164110                  |
| Jonyo Janny              | 166885                  |
| Ogutu Cindy Atieno       | 158842                  |
| Mukoma Dennis Murage     | 139360                  |
| Kemoi Kristina Chebet    | 168652                  |
| Mapelu Neema Naserian    | 150176                  |

---

## Section 1: Environmental Requirements for Daisy Growth

### Introduction

Flora Farms operates greenhouses in Naivasha, Kenya, to cultivate various flower species for local and export markets. This project focuses on daisies (*Leucanthemum* spp.), which require specific environmental conditions for optimal growth and flowering. Understanding these requirements is essential for designing an embedded monitoring system capable of collecting environmental data and supporting remote greenhouse management.

### Table 1: Environmental Requirements for Daisy Growth

| Parameter             | Optimal Range / Condition                                    |
|-----------------------|--------------------------------------------------------------|
| Temperature           | 15°C – 24°C                                                  |
| Relative Humidity     | 40% – 60% RH                                                 |
| Soil Type             | Well-drained loamy or sandy-loam soil rich in organic matter |
| Soil Moisture Content | 40% – 60% Field Capacity                                     |
| Soil pH               | 6.0 – 6.8                                                    |
| Sunlight Exposure     | 6 – 8 hours of direct sunlight per day                       |

**Temperature**

Daisies are cool-season flowering plants that perform best between 15°C and 24°C. Temperatures below this range slow growth and flowering, while temperatures above 30°C can cause heat stress, wilting, and reduced flower quality.

**Relative Humidity**

An ideal humidity range of 40% – 60% supports healthy transpiration and nutrient movement within the plant. Excess humidity may encourage fungal diseases, while low humidity can increase water stress.

**Soil Type**

Daisies thrive in well-drained loamy or sandy-loam soils with sufficient organic matter. Such soils provide a balance between water retention and root aeration.

**Soil Moisture Content**

The soil should remain moderately moist, approximately 40% – 60% of field capacity. Overly dry soil reduces growth and flowering, while excessive moisture can cause root diseases.

**Soil pH**

Daisies grow best in slightly acidic to near-neutral soils with a pH range of 6.0 – 6.8. This range ensures efficient nutrient availability and uptake.

**Sunlight Exposure**

Daisies require full sun exposure and should receive approximately 6 – 8 hours of direct sunlight daily to maximise flowering and plant vigour.

---

## Section 2: Hardware Components Required

The greenhouse monitoring system requires the following hardware components:

### Table 2: Hardware Components

| Component                                      | Quantity | Purpose                                           |
|------------------------------------------------|----------|---------------------------------------------------|
| ESP32S DevKit Wi-Fi + BLE Module (30 Pin)      | 1 – 2    | Main microcontroller and wireless communication   |
| DHT22 (AM2302) Temperature and Humidity Sensor | 1        | Measures temperature and relative humidity        |
| MQ-5 Gas Sensor                                | 1        | Detects LPG, methane and natural gas              |
| 1.3" OLED Display (128 × 64, I²C)              | 1        | Displays environmental readings locally           |
| 5V Single Channel Relay Module                 | 1        | Controls switching operations between ESP32 nodes |
| Breadboard                                     | 1        | Circuit prototyping                               |
| Jumper Wires (Male-to-Male / Male-to-Female)   | Several  | Electrical connections between components         |
| 10 kΩ Resistor                                 | 1        | DHT22 data line pull-up                           |
| 220 Ω – 1 kΩ Resistors                         | Several  | Signal conditioning and voltage division          |
| 100 nF Capacitor                               | 2        | Decoupling / noise filtering on ESP32 supply pins |
| 10 µF Capacitor                                | 1        | Bulk power stabilisation                          |
| USB Cable                                      | 1        | Programming and powering the ESP32                |
| 5V Power Supply                                | 1        | Powers sensors and relay module                   |

---

## Section 3: Datasheet Collection

The following datasheets and technical references were collected for the components required in the project:

### Table 3: Datasheets and Technical References

| Component | Datasheet / Technical Reference |
|-----------|---------------------------------|
| ESP32S DevKit Wi-Fi + BLE Module (30 Pin) | [ESP32-WROOM-32 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf) |
| DHT22 (AM2302) Temperature and Humidity Sensor | [DHT22 Datasheet](https://cdn-shop.adafruit.com/datasheets/DHT22.pdf) |
| MQ-5 Gas Sensor | [MQ-5 Datasheet](https://www.winsen-sensor.com/d/files/manual/mq-5.pdf) |
| 1.3" OLED Display (128 × 64, I²C) | [SSD1306 OLED Controller Datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf) |
| 5V Single Channel Relay Module | [Product Documentation](https://components101.com/switches/5v-single-channel-relay-module-pinout-features-applications-working-datasheet) |

---

### 1. ESP32S DevKit Wi-Fi + BLE Module (30 Pin)

**Official Datasheet:** https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf  

**Manufacturer:** https://www.espressif.com

**Key Specifications**
- Operating Voltage: 3.3 V
- Wi-Fi: IEEE 802.11 b/g/n
- Bluetooth: BLE and Classic Bluetooth
- Dual-Core Xtensa LX6 Processor
- Multiple GPIO Pins

---

### 2. DHT22 (AM2302) Temperature and Humidity Sensor

**Datasheet:** https://cdn-shop.adafruit.com/datasheets/DHT22.pdf

**Key Specifications**
- Temperature Range: −40°C to 80°C
- Humidity Range: 0 – 100% RH
- Temperature Accuracy: ±0.5°C
- Humidity Accuracy: ±2 – 5% RH
- Operating Voltage: 3.3 V – 6 V

---

### 3. MQ-5 LPG / Natural Gas Sensor

**Datasheet:** https://www.winsen-sensor.com/d/files/manual/mq-5.pdf  

**Manufacturer:** https://www.winsen-sensor.com

**Key Specifications**
- Detects LPG
- Detects Methane
- Detects Natural Gas
- Operating Voltage: 5 V
- Analogue and Digital Outputs

---

### 4. 1.3" OLED Display (128 × 64, I²C)

**SSD1306 Controller Datasheet:** https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf

**Key Specifications**
- Resolution: 128 × 64 Pixels
- I²C Communication Interface
- Low Power Consumption
- Compatible with ESP32

> **Note:** Most 1.3" OLED modules use either the SSD1306 or SH1106 controller. The SSD1306 datasheet is provided as the primary reference.

---

### 5. 5V Single Channel Relay Module

**Technical Reference:** https://components101.com/switches/5v-single-channel-relay-module-pinout-features-applications-working-datasheet

**Key Specifications**
- Operating Voltage: 5 V
- Single Channel
- Low-Level Trigger
- Supports AC and DC Loads
- Opto-isolation available on some variants

---

## Section 4: Schematic Diagrams

### Architecture A: 1 ESP32S connected to 1 MQ-5, 1 DHT22 and 1 OLED Display

**Components:**
- ESP32 number 1
- ESP32 number 2
- MQ-5
- DHT22
- OLED Display
- 10 kΩ resistor
- 2 kΩ resistor
- 1 kΩ resistor
- Capacitors
- Voltage divider
- UART communication lines

> The MQ-5 operates at 5 V but the ESP32 ADC input pins are 3.3 V tolerant. A voltage divider (R2/R3) is therefore placed on the MQ-5 analogue output before it reaches GPIO34.

<img width="1169" height="827" alt="Question 4a" src="https://github.com/user-attachments/assets/9b022da0-6a7a-45ed-8936-73e173c060b3" />

---

### Architecture B: 1 ESP32S connected to 1 MQ-5, interfaced directly with another ESP32S connected to 1 DHT22

**Components**

- ESP32 number 1
- ESP32 number 2
- MQ-5
- DHT22
- 10 kΩ resistor
- 2 kΩ resistor
- 1 kΩ resistor
- Capacitors
- Voltage divider
- UART communication lines

<img width="1169" height="828" alt="Question 4b" src="https://github.com/user-attachments/assets/5db4bb65-cc0a-4ec4-9115-2e04ac2898a1" />

---

### Architecture C: 1 ESP32S connected to 1 DHT22, connected to 1 relay, which is connected to another ESP32S connected to 1 MQ-5

**Components used:**
- ESP32 number 1
- ESP32 number 2
- MQ-5
- DHT22
- Relay module (1-channel, 5V)
- 10 kΩ resistor
- 2 kΩ resistor
- 1 kΩ resistor
- Capacitors
- Voltage divider
- Relay switching contacts (COM/NO)

<img width="1172" height="829" alt="Question 4c" src="https://github.com/user-attachments/assets/f6efdb75-6ec1-4d86-b095-295172a1cfe9" />

---

*ICS 4111 — Embedded Systems & IoT | Flora Farms Greenhouse Monitoring Project | SweetHertz Group* 

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-09 at 23 46 09" src="https://github.com/user-attachments/assets/0c4fb73f-2ac3-4711-a4dc-6d093ae05b9e" />
