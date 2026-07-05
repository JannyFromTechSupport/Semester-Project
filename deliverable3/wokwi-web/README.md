# Wokwi Web Alternative

Use this folder if PlatformIO is not compiling.

1. Go to https://wokwi.com/projects/new/esp32
2. Replace the default sketch with `sketch.ino`.
3. Add or replace `diagram.json`.
4. Add `libraries.txt`.
5. Start the simulation.
6. Open the serial monitor at 115200 baud.

Expected serial output:

```text
ESP32 started
Initializing LCD...
Initializing DHT22...
```

Expected LCD startup:

```text
SweetHertz
LCD OK
```
