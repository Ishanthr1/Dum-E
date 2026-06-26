# Dum-E Build Journal

DumE is a voice controlled autonomous mobile manipulator: a 6 DOF arm on a
holonomic (mecanum) drive base, with stereo vision, natural language control, and a
personality system. The chassis and arm are designed and built **from scratch** from
individually sourced components.

---

## June 19: Design Phase: Drive Base Layout
**Hours: 2**

- Started the CAD design for DumE and laid out the holonomic drive base footprint (~30 × 25 cm).
- Positioned the four mecanum wheels at the corners and set the roller angle to 45° for true omnidirectional travel; checked wheel clearance against the chassis edges.
- Blocked out the lower deck and planned where the four DC gear motors and the motor driver would sit.
- Locked in the overall proportions so the base is wide and low enough to stay stable once the arm is mounted on top.

<img width="597" height="573" alt="Screenshot 2026-06-24 at 9 28 25 PM" src="https://github.com/user-attachments/assets/00ae0823-ab07-4602-a3a0-f2d65ee8fb4d" />


---

## June 20: Design Phase: Arm Mount, Camera Housing & Electronics Bay
**Hours: 3**

- Added the rotating shoulder turret / arm mount at the rear center of the deck.
- Modeled the central electronics bay enclosure to house the Raspberry Pi 5 and the driver boards, plus a removable tray for the LiPo battery.
- Roughed in the camera housing for the stereo vision head.

- Worked out counterweight placement: the arm shifts the center of mass forward when extended, so I positioned the battery toward the rear to keep the platform from tipping.

<img width="841" height="546" alt="Screenshot 2026-06-24 at 9 24 28 PM" src="https://github.com/user-attachments/assets/128e1ce1-2558-4232-a2c9-990e0867ccc6" />
<img width="520" height="646" alt="Screenshot 2026-06-24 at 9 24 57 PM" src="https://github.com/user-attachments/assets/0cceaaaf-8d6b-44b8-bf40-26c15ce0926d" />


---

## June 21: Design Phase: 6-DOF Arm & Gripper
**Hours: 4**

- Designed the full 6 DOF arm from scratch: shoulder, elbow, and wrist joints, each driven by a high torque servo in its own aluminum bracket.
- Sized the link segments (slim aluminum plates with lightening cutouts and cable channels) to keep the arm short and stout rather than gangly, so the servos aren't fighting a long moment arm.
- Designed the parallel jaw gripper as a single 3D printed assembly actuated by a small servo, with textured fingertips for grip.
- Sanity checked reach and joint ranges so the gripper can actually reach the ground and objects on the deck this feeds directly into the inverse kinematics work later.

<img width="450" height="645" alt="Screenshot 2026-06-24 at 9 26 03 PM" src="https://github.com/user-attachments/assets/1aa77b50-377c-46b1-8c12-42b37f1bfa0a" />
<img width="353" height="418" alt="Screenshot 2026-06-24 at 9 26 24 PM" src="https://github.com/user-attachments/assets/a5d24510-c82c-4fa7-9304-c766e2ab5cee" />
<img width="651" height="527" alt="Screenshot 2026-06-24 at 9 26 56 PM" src="https://github.com/user-attachments/assets/8a55412d-ef02-426a-bc1d-8bb1d470e7fd" />
<img width="790" height="517" alt="Screenshot 2026-06-24 at 9 26 42 PM" src="https://github.com/user-attachments/assets/0fa11665-f54e-48d8-a5ee-fdbb21e9a68c" />


---

## June 22: Design Phase: Vision Head, Power Routing & Scratch-Build Rework
**Hours: 4**

- Switched from off the shelf kit parts to a fully scratch built chassis and arm, and redid the CAD for cleaner, more precise geometry real brackets, fillets, and fastener holes instead of blocky placeholders.
- Designed the 3D printed pan tilt sensor head carrying the stereo camera pair (fixed baseline) with the ReSpeaker mic array disc mounted on top.
- Planned the power and wiring path: LiPo → buck converter → Pi 5 and logic, with a separate motor power rail and routing channels so no wires are left floating.
- Fixed assembly issues from the earlier draft so every part is connected and seated, with nothing detached.

<img width="175" height="64" alt="Screenshot 2026-06-24 at 9 29 00 PM" src="https://github.com/user-attachments/assets/f3f78b8c-afc9-4b6a-a82a-75aef42d5c0e" />
<img width="231" height="131" alt="Screenshot 2026-06-24 at 9 29 51 PM" src="https://github.com/user-attachments/assets/2c0821a6-e826-487c-96d9-cb2f1e5328df" />

---

## June 23: Design Phase: Final Review & Submission
**Hours: 2**

- Finished the full design and reviewed it from all angles (iso, top, front, side) to confirm fit and clearances.
- Exported the CAD files and added them to the repository.

<img width="648" height="575" alt="Screenshot 2026-06-24 at 9 30 17 PM" src="https://github.com/user-attachments/assets/b148601f-7374-4ed4-bfc9-e0997ebda685" />
<img width="472" height="536" alt="Screenshot 2026-06-24 at 9 30 37 PM" src="https://github.com/user-attachments/assets/d0d52740-92b3-4e3c-9b50-e7561ad16590" />
<img width="475" height="543" alt="Screenshot 2026-06-24 at 9 30 50 PM" src="https://github.com/user-attachments/assets/03f3a591-b380-4608-a71b-d1b2dd14d0e8" />


---

**Total hours: 15**
