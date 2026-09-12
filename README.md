# Dum-E

A voice controlled autonomous mobile manipulator built from scratch. Dum-E is a 6 DOF robotic arm mounted on a holonomic (mecanum) drive base named after Tony Stark's clumsy robot assistant.

<img width="891" height="684" alt="Screenshot 2026-08-04 at 3 30 15 PM" src="https://github.com/user-attachments/assets/217c6ad9-1f26-4ea8-bd6a-377a9a5e44ae" />



## Overview and How it Works

DumE is a robotic platform with two main sub assemblies: a holonomic drive base and a 6 DOF arm. Both the chassis and the arm are designed and built from scratch from individually sourced aluminum, hardware, and 3D printed parts.

- **Holonomic drive:** four mecanum wheels for omnidirectional movement (forward, strafe, and rotate in place).
- **6-DOF arm:** six high torque servos with a custom parallel jaw gripper.
- **Stereo vision head:** dual Raspberry Pi cameras at a fixed baseline.
- **Far-field audio:** ReSpeaker mic array plus an amplified speaker.

CAD files for the chassis, arm, and 3D printed parts are in the [`cad/`](cad/) folder.

## Why?

I have always been interested in Robotics and building this project can help me improve me skills. There are already many prebuilt things I can buy to help speed up this project but I want to make something actually worthwhile which is why I am building everything from scratch from individually sourced parts. I also wanted to make something cool!

## Bill of Materials

Full parts list (also available as [`BOM.csv`](BOM.csv)). A Raspberry Pi 5 is required but is owned separately and not included in the total below.

| Item | Qty | Unit (USD) | Where to buy |
|------|-----|------------|--------------|
| Hiwonder xArm1S 6DOF arm (unassembled) | 1 | 199.99 | [Amazon](https://www.amazon.com/Programming-Powerful-Intelligent-Featuring-Unassembled/dp/B08FT31C5N) |
| MC200 mecanum chassis + 4 encoder motors | 1 | 49.99 | [Amazon](https://www.amazon.com/dp/B09KL37P43) |
| Raspberry Pi Camera Module 3 (stereo pair) | 2 | 25.00 | [Adafruit](https://www.adafruit.com/product/5657) |
| LiPo battery 3S 11.1V (XT60) | 1 | 22.00 | [Amazon](https://www.amazon.com/s?k=3S+11.1V+lipo+battery+xt60) |
| LiPo balance charger (3S) | 1 | 18.00 | [Amazon](https://www.amazon.com/s?k=lipo+3s+balance+charger) |
| Buck converter 7.5V 6A — arm rail | 1 | 14.00 | [Amazon](https://www.amazon.com/s?k=DC-DC+buck+converter+7.5V+6A+adjustable) |
| USB webcam — arm head camera | 1 | 15.00 | [Amazon](https://www.amazon.com/s?k=usb+webcam+1080p+mini) |
| Powered USB hub | 1 | 15.00 | [Amazon](https://www.amazon.com/s?k=powered+usb+hub+3.0) |
| ReSpeaker 2-Mics Pi HAT | 1 | 12.00 | [Seeed Studio](https://www.seeedstudio.com/ReSpeaker-2-Mics-Pi-HAT.html) |
| microSD card 32GB high-speed | 1 | 12.00 | [Amazon](https://www.amazon.com/s?k=samsung+evo+select+32gb+microsd) |
| ESP32 dev board — motor controller | 1 | 10.00 | [Amazon](https://www.amazon.com/s?k=esp32+devkit+v1) |
| Buck converter 5V 5A (UBEC) | 1 | 9.00 | [Amazon](https://www.amazon.com/s?k=5V+5A+UBEC+buck+converter) |
| XT60 connectors + power wiring | 1 | 8.00 | [Amazon](https://www.amazon.com/s?k=xt60+connector+wire) |
| L298N dual H-bridge motor driver | 2 | 7.00 | [Amazon](https://www.amazon.com/s?k=L298N+motor+driver) |
| Inline fuse holder + master switch | 1 | 6.00 | [Amazon](https://www.amazon.com/s?k=inline+fuse+holder+rocker+switch+12v) |
| Raspberry Pi 5 active cooler | 1 | 10.00 | [Adafruit](https://www.adafruit.com/product/5815) |
| MAX98357A I2S audio amplifier | 1 | 5.95 | [Adafruit](https://www.adafruit.com/product/3006) |
| Speaker 3in 8 ohm 1W | 1 | 1.95 | [Adafruit](https://www.adafruit.com/product/1313) |
| M3 socket-head screw + nut assortment | 1 | 13.00 | [Amazon](https://www.amazon.com/s?k=M3+socket+head+screw+nut+assortment) |
| M3 brass standoff kit | 1 | 9.00 | [Amazon](https://www.amazon.com/s?k=M3+brass+standoff+kit) |
| 3D printer filament (PETG 1kg) | 1 | 20.00 | [Amazon](https://www.amazon.com/s?k=PETG+filament+1kg) |
| Dupont jumper wire kit | 1 | 10.00 | [Amazon](https://www.amazon.com/s?k=dupont+jumper+wire+kit) |

**Parts total: ~$520.88** (grant-funded core: ~$399.88 · self-funded: ~$121.00)

## Build Journal

Day by day progress is logged in Journal.md.


## License

MIT see [`LICENSE`](LICENSE).
