# 🌱 Automated Crop Watering System (Summer 2025)  

*A solar-powered closed-loop system that monitors soil moisture and irrigates crops using recycled rainwater*

![System Diagram](https://via.placeholder.com/600x400?text=System+Diagram) <!-- Replace with actual image -->

## 📌 Key Features
- ♻️ **Rainwater Recycling**: Collects and reuses rainfall from a 50L barrel
- 💧 **Precision Irrigation**: Waters only when soil moisture < threshold (adjustable)
- ☀️ **Off-Grid Operation**: 10W solar panel + 18650 battery pack
- 📊 **Data Logging**: Tracks moisture/watering events (CSV or cloud upload)
- 💰 **Low-Cost**: < $150 total (RPi + Arduino + affordable sensors)

## 🛠️ Hardware Components
| Component                            | Purpose                                         |
|--------------------------------------|-------------------------------------------------|
| Raspberry Pi 4                       | Main controller (data logging/pump control)     |
| Arduino Uno                          | Reads analog soil moisture sensor               |
| 5V Relay Module                      | Analog converter to link arduino and water pump |
| Capacitive Soil Sensor               | Measures real-time moisture % (0-100%)          |
| 5V Water Pump                        | Delivers water from rain barrel                 |
| Relay Module                         | Safely controls pump with Pi GPIO               |
| 40000 mAh Solar Paneled Power Bank   | Charges battery during daylight                 |
| 50L Water Bowl                       | Rainwater collection                            |

## 📊 Performance Metrics
After **8 weeks** of continuous monitoring:

### Water Savings
| Metric                | Value       |
|-----------------------|-------------|
| Manual watering       | 120L/week   |
| Automated system      | 72L/week    |
| **Reduction**         | **40%**     |

![Moisture Graph](https://via.placeholder.com/600x300?text=Moisture+vs+Time+Graph) <!-- Add real graph -->

> **Peaks** show pump activations (only when moisture <20%). No unnecessary watering.

### Crop Health Insights
- ✅ **Optimal range**: 20–60% moisture (plants showed 30% faster growth vs manual)
- ⚠️ **Stress detected**: <15% moisture triggered leaf curling
- 🚫 **Root rot prevention**: Zero instances of sustained >80% moisture

### System Efficiency
- 🔋 **Solar performance**: 10W panel maintained 4.2V battery even on cloudy days
- ⚡ **Power draw**: 0.8W idle / 5W during pumping
- 🛠️ **Maintenance**: Required sensor recalibration every 2 weeks

## 🚀 Getting Started
```bash
git clone https://github.com/yourusername/automated-watering-system.git
cd automated-watering-system
pip install -r requirements.txt
