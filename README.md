# AIot-Gesture
# 🤖✨ AIoT Gesture-Based Light Control

A smart and touchless lighting system that uses **AI-based hand gesture recognition** to control lights via the **internet** using **Firebase** and **ESP32**. Perfect for smart homes, hygiene-sensitive environments, or futuristic automation demos.

---

## 🚀 Features

- ✋ AI-powered **hand gesture detection** using webcam and MediaPipe
- 🌐 **Real-time cloud control** using Firebase Realtime Database
- 📶 **ESP32 with relay** to switch lights/appliances from anywhere
- 🧠 **Touchless & silent** control without physical switches or voice
- 💡 Ideal for homes, hospitals, or IoT learning projects

---

## 🛠️ Technologies Used

- **Python** – Gesture detection
- **MediaPipe** – Hand landmark recognition
- **Firebase** – Cloud communication
- **ESP32** – IoT microcontroller
- **Relay Module** – Light/appliance switching
- **Arduino IDE** – Programming ESP32

---

## 📦 Project Structure

AIoT-Gesture-Light-Control/
├── python-gesture/
│ ├── gesture_control.py # Main gesture detection script
│ └── firebase_update.py # Updates Firebase with gesture state
├── esp32-code/
│ └── light_control.ino # ESP32 code to read Firebase and toggle relay
├── assets/
│ └── demo.gif # Demo images/gifs
├── README.md
└── requirements.txt


---

## 🧠 How It Works

1. **Webcam + Python + MediaPipe** detects specific hand gestures (like open palm or fist).
2. Detected gestures are mapped to commands and sent to **Firebase**.
3. An **ESP32** board constantly listens to Firebase.
4. Based on the received command, it turns **lights ON/OFF** using a **relay**.

---

## 🔌 Hardware Requirements

- ESP32 Dev Board
- Relay Module (5V)
- USB Cable for ESP32
- Light Bulb (or any switchable appliance)
- Webcam for gesture input

---

## 💻 Software Setup

### Python Environment

```bash
git clone https://github.com/your-username/AIoT-Gesture-Light-Control.git
cd AIoT-Gesture-Light-Control/python-gesture
pip install -r requirements.txt
python gesture_control.py

ESP32 Setup

    Open light_control.ino in Arduino IDE.

    Replace WIFI_SSID, PASSWORD, and FIREBASE_URL.

    Upload to ESP32.

🎥 Demo

💡 Future Improvements

    Add voice + gesture hybrid control

    Deploy AI gesture recognition on Raspberry Pi

    Add UI for manual override and logs

    Use ML models for custom gestures

🔐 License

This project is open-source and MIT licensed.
Feel free to modify and improve it!
🤝 Contributing

Pull requests and ideas are welcome!
If you find bugs or want new features, please open an issue.
🙌 Credits

    MediaPipe

    Firebase

    ESP32 Docs
