# Automated Crop Watering System Using Soil Moisture Sensors

## Project Goal

The objective of this project was to **automate the watering of crops** based on real-time soil moisture levels and compare the **water consumption** between an automated system and a manual, regularized watering process.

### Hypothesis

I hypothesize that the automated system would use approximately **30% less water** than manual watering by hand.

---

## Materials and Setup

### Raised Bed Construction

To grow the test crops, I purchased a **4ft x 2ft x 1ft metal raised bed** for $50. I opted for a **metal bed** instead of wood due to its longer durability and resistance to rot without requiring treatment. The chosen size was ideal for a beginner gardening setup.

**Construction Steps:**

1. Assembled using screws and bolts to connect metal sheets.
2. Added a layer of **cardboard** at the bottom to suppress weed growth.
3. Applied a **layer of mulch** for drainage and cost-efficiency (less soil required).
4. Filled the bed with a **mixture of garden soil and sheep manure compost**.

---

### Automation Setup

To automate the system, I used the following components:

- **Raspberry Pi 4** as the main computer.
- **Arduino Uno** to interface with:
  - **Soil Moisture Sensor**
  - **5V Relay Module**
  - **Water Pump**
- Power provided by a **40,000 mAh solar power bank** (initially).
- **Rainwater bin** as the water reservoir.
- All components connected using jumper wires and breadboards.

> 📎 **Schematics and wiring diagram:** [Insert schematic image or repo link here]  
> 🧠 **Code & connections reference:** [Insert code repo or Arduino sketch link here]

---

## Challenges and Solutions

### 1. **Power Supply Issue**

Initially, the system was intended to be powered by a **solar power bank** advertised as 40,000 mAh. However, the solar charging capabilities were found to be **unreliable**, with minimal charging over an entire week of direct sunlight.

**Solution:**  
I had to **run an extension cord** from my house to power the system. For future iterations, I recommend investing in a **legitimate 30W+ solar panel** if complete off-grid functionality is desired.

---

### 2. **Pump Pulsing & System Resets**

The pump would only pulse briefly rather than run for a full second. This issue coincided with repeated serial monitor messages such as `System Ready (Protected)`, indicating an unexpected Arduino reset.

**Investigation Steps:**

- Replaced **aligator clips** with soldered connections (no change).
- Suspected **poor breadboard and jumper wire connections**.
- Found that **relay contact with other electronics** was triggering resets.

**Cause:**  
Based on research, this was likely due to **electrical interference or grounding issues**, as described by DeepSeek AI:

> "Electromagnetic noise from the relay, back-EMF spikes, or power supply instability can disrupt the control circuit, leading to rapid on/off cycling instead of a steady output."

**Solution:**  
I **isolated the Arduino** by wrapping it in a **plastic bag** to avoid interference—this stabilized the system.

---

### 3. **Python-Arduino Serial Conflict**

The goal was to automate data logging into a **SQLite database using Python**, but Python could not read from the Arduino while its sketch was running, due to **serial port conflict** (only one program can access the port at a time).

**Solution:**  
I continued using the **Arduino sketch for automation** and manually recorded data from the **serial monitor** into an Excel sheet.

---

## Data Collection

### Moisture Reading

The soil moisture sensor outputs analog values:

- **475 = Dry (sensor in air)**
- **200 = Wet (sensor submerged in water)**

From these values, I calculated moisture percentage. I set a **threshold of 15%** as the minimum moisture level that would **trigger watering**. This value may be adjusted with more data over time.

### Watering Volume Estimate

- The pump outputs approximately **50–75 mL/sec**.
- Watering events are triggered with **1-second bursts**, thus 50–75 mL per activation.

---

## Data Logs

All collected data can be found in the Excel sheet:

- [📊 Excel Sheet with Moisture & Watering Logs](insert-link-here)

### Contents:

- **Daily moisture readings**
- **Watering events** (manual vs automated)
- **Environmental data** (temperature, humidity, weather)

---

## Conclusion

This project demonstrated the feasibility of **automated watering based on real-time soil moisture**. While the system faced challenges related to **power reliability** and **hardware interference**, the setup became stable after several iterations.

Future improvements may include:

- Integrating **a higher-quality solar panel**
- Replacing unreliable jumper wires with **custom PCB or solid soldering**
- Using **Wi-Fi enabled logging** for real-time remote tracking
- Improving software integration between Arduino and Python

---

## Recommendations

If you're attempting this project yourself:

- **Test your power supply thoroughly.**
- **Use high-quality connectors and cables.**
- **Isolate sensitive electronics** to avoid interference.
- Consider using a **LoRa or Wi-Fi-based remote logging system** to streamline data collection.

---

## Media

- 🖼️ Image of final raised bed: *(insert image link or embed)*
- 🧠 Arduino Code and Wiring: *(insert link)*
- 📊 Excel Data Sheet: *(insert link)*

---

## License

MIT License (or your chosen license).

---
