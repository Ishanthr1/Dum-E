# Dum-E

A voice controlled autonomous mobile manipulator built from scratch. Dum-E is a 6 DOF robotic arm mounted on a holonomic (mecanum) drive base named after Tony Stark's clumsy robot assistant.

<img width="573" height="553" alt="Screenshot 2026-06-24 at 9 44 03 PM" src="https://github.com/user-attachments/assets/4e829d02-bca1-431c-990b-185d8edc2f24" />

> **Status:** Design & build phase. The chassis and arm are designed from scratch and being fabricated from individually sourced components.

---

## Overview

DumE is a robotic platform with two main sub-assemblies: a holonomic drive base and a 6 DOF arm. Both the chassis and the arm are designed and built from scratch from individually sourced aluminum, hardware, and 3D printed parts.

- **Holonomic drive:** four mecanum wheels for omnidirectional movement (forward, strafe, and rotate in place).
- **6-DOF arm:** six high-torque servos with a custom parallel-jaw gripper.
- **Stereo vision head:** dual Raspberry Pi cameras at a fixed baseline.
- **Far-field audio:** ReSpeaker mic array plus an amplified speaker.

CAD files for the chassis, arm, and 3D printed parts are in the [`cad/`](cad/) folder.

## Bill of Materials

Full parts list (also available as [`BOM.csv`](BOM.csv)). A Raspberry Pi 5 is required but is owned separately and not included in the total below.

| Item | Qty | Unit (USD) | Where to buy |
|------|-----|-----------|--------------|
| DS3218 20kg digital servo (2-pack) — arm joints | 3 | 27.99 | [Amazon](https://www.amazon.com/DS3218-Digital-Servo-Torque-Waterproof/dp/B07TKTQ2NZ) |
| PCA9685 16-channel servo driver | 1 | 14.95 | [Adafruit](https://www.adafruit.com/product/815) |
| Micro servo (SG92R) — gripper actuator | 1 | 5.95 | [Adafruit](https://www.adafruit.com/product/169) |
| 6061 aluminum sheet 3mm — arm links/brackets | 1 | 20.00 | [OnlineMetals](https://www.onlinemetals.com/en/buy/aluminum) |
| Mecanum wheel kit 80mm (4 wheels) | 1 | 19.60 | [DFRobot](https://www.dfrobot.com/product-2042.html) |
| DC gear motor w/ encoder 12V (JGB37-520 type) | 4 | 13.00 | [Amazon](https://www.amazon.com/s?k=JGB37-520+12V+encoder+gear+motor) |
| 6mm hex coupling (wheel-to-shaft) | 4 | 4.00 | [Amazon](https://www.amazon.com/s?k=6mm+hex+coupling+mecanum) |
| L298N dual H-bridge motor driver | 2 | 7.00 | [Amazon](https://www.amazon.com/s?k=L298N+motor+driver) |
| 6061 aluminum sheet 3mm — chassis plates | 1 | 22.00 | [OnlineMetals](https://www.onlinemetals.com/en/buy/aluminum) |
| LiPo battery 3S 11.1V (XT60) | 1 | 22.00 | [Amazon](https://www.amazon.com/s?k=3S+11.1V+lipo+battery+xt60) |
| LiPo balance charger (3S) | 1 | 18.00 | [Amazon](https://www.amazon.com/s?k=lipo+3s+balance+charger) |
| Buck converter / 5V 5A regulator | 1 | 10.00 | [Amazon](https://www.amazon.com/s?k=5V+5A+buck+converter) |
| XT60 connectors + power wiring | 1 | 8.00 | [Amazon](https://www.amazon.com/s?k=xt60+connector+wire) |
| Raspberry Pi Camera Module 3 (stereo pair) | 2 | 25.00 | [Adafruit](https://www.adafruit.com/product/5657) |
| ReSpeaker 4-Mic Array for Raspberry Pi | 1 | 24.90 | [Seeed Studio](https://www.seeedstudio.com/ReSpeaker-4-Mic-Array-for-Raspberry-Pi.html) |
| Speaker 3in 8 ohm 1W | 1 | 1.95 | [Adafruit](https://www.adafruit.com/product/1313) |
| MAX98357A I2S audio amplifier | 1 | 5.95 | [Adafruit](https://www.adafruit.com/product/3006) |
| M3 socket-head screw + nut assortment | 1 | 13.00 | [Amazon](https://www.amazon.com/s?k=M3+socket+head+screw+nut+assortment) |
| Ball bearing assortment (608) | 1 | 10.00 | [Amazon](https://www.amazon.com/s?k=608+ball+bearing+assortment) |
| Shaft collars / couplers assortment | 1 | 8.00 | [Amazon](https://www.amazon.com/s?k=shaft+collar+coupler+assortment) |
| M3 brass standoff kit | 1 | 9.00 | [Amazon](https://www.amazon.com/s?k=M3+brass+standoff+kit) |
| 3D printer filament (PETG 1kg) | 1 | 20.00 | [Amazon](https://www.amazon.com/s?k=PETG+filament+1kg) |
| Dupont jumper wire kit | 1 | 10.00 | [Amazon](https://www.amazon.com/s?k=dupont+jumper+wire+kit) |

**Parts total: ~$459.27**.

## Repository Structure

```
Dum-E/
├── README.md      # this file
├── Journal.md     # build log
├── BOM.csv        # bill of materials
├── cad/           # CAD files & 3D-print STLs
└── images/        # photos & renders
```

## Build Journal

Day by day progress is logged in [`Journal.md`](Journal.md).


## License

MIT see [`LICENSE`](LICENSE).
