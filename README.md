# HUMA-USV-UI — Ground Control Station (Qt)
A lightweight Qt (C++) Ground Control Station for an Uncrewed Surface Vehicle (USV). Includes map-based mission planning, live telemetry, charts, and an emergency action.
# Screenshot
![prew](https://github.com/Difyeli/huma-usv-ui/blob/2050f3b03f4c28329ec0d691521ed7e9a68c5a2f/ScreenShot.png)

# Features
-	Map mission planning (add/delete waypoints, send to vehicle)
-	Live vehicle position and heading
-	Connection panel (Serial or UDP, baud, status)
-	Telemetry (yaw, setpoint yaw, speed, RC/failsafe, left/right thruster PWMs)
-	Charts: Speed, PWM, Heading
-	Emergency button, basic Settings, optional CSV logging
# Requirements
-	Qt 5.15+ or Qt 6.x (Widgets, Charts, SerialPort, Network, Quick/QML, Location/Positioning)
-	C++17 compiler
-	Windows 10/11 or Ubuntu 20.04/22.04
-	(Optional) Map tile API key
# Quick Start
-	Clone the repo and open deneme.pro in Qt Creator.
-	Choose your Kit, build, and run.
-	On Linux, add your user to the dialout group for serial access.
# Configuration
-	Connection: choose port (e.g., /dev/ttyUSB0 or COM3) and baud; or set UDP IP/ports.
-	Map: enter tile URL and API key in Settings (otherwise you may see “API Key Required”).
-	Logging: enable CSV logs if desired (saved with timestamps).
# Usage
-	Power the vehicle and click CONNECT.
-	Add latitude/longitude pairs in Quest Log, then SEND.
-	Monitor Speed, PWM, and Heading charts.
-	Use EMERGENCY for immediate stop/failsafe.
