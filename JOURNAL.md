# Dum-E Build Journal

DumE is a voice controlled autonomous mobile manipulator: a 6 DOF arm on a
holonomic (mecanum) drive base, with stereo vision, natural language control, and a
personality system. The chassis and arm are designed and built from
individually sourced components.

---

## June 19: Design Phase: Drive Base Layout
**Hours: 2**

- Started the CAD design for DumE and laid out the holonomic drive base footprint.
- Positioned the four mecanum wheels at the corners and set the roller angle to 45° for true omnidirectional travel; checked wheel clearance against the chassis edges.
- Blocked out the lower deck and planned where the four DC gear motors and the motor driver would sit.
- Locked in the overall proportions so the base is wide and low enough to stay stable once the arm is mounted on top.

<img width="462" height="387" alt="Screenshot 2026-08-04 at 3 35 26 PM" src="https://github.com/user-attachments/assets/c476b3f6-0a6a-420e-af90-1717d4d928f4" />

---

## June 20: Design Phase: Arm Mount, Camera Housing & Electronics Bay
**Hours: 3**

- Added the rotating shoulder turret / arm mount at the rear center of the deck.
- Modeled the central electronics bay enclosure to house the Raspberry Pi 5 and the driver boards, plus a removable tray for the LiPo battery.
- Roughed in the camera housing for the stereo vision head.

- Worked out counterweight placement: the arm shifts the center of mass forward when extended, so I positioned the battery toward the rear to keep the platform from tipping.

<img width="771" height="496" alt="Screenshot 2026-08-04 at 3 35 58 PM" src="https://github.com/user-attachments/assets/dab6ab85-8ca5-42f3-927d-ca8476a861f4" />
<img width="378" height="293" alt="Screenshot 2026-08-04 at 3 36 22 PM" src="https://github.com/user-attachments/assets/c13d7edd-d270-452f-9794-7f77e6069bf1" />
<img width="374" height="210" alt="Screenshot 2026-08-04 at 3 36 35 PM" src="https://github.com/user-attachments/assets/a85458b5-51b0-4faa-bb70-c9c18b204879" />
<img width="347" height="243" alt="Screenshot 2026-08-04 at 3 36 50 PM" src="https://github.com/user-attachments/assets/39d0ab79-5b4f-4642-94b1-8a5d7a7ae1ff" />

---

## June 21: Design Phase: 6-DOF Arm & Gripper
**Hours: 4**

- Designed the full 6 DOF arm from scratch: shoulder, elbow, and wrist joints, each driven by a high torque servo in its own aluminum bracket.
- Sized the link segments (slim aluminum plates with lightening cutouts and cable channels) to keep the arm short and stout rather than gangly, so the servos aren't fighting a long moment arm.
- Designed the parallel jaw gripper as a single 3D printed assembly actuated by a small servo, with textured fingertips for grip.
- Sanity checked reach and joint ranges so the gripper can actually reach the ground and objects on the deck this feeds directly into the inverse kinematics work later.

<img width="771" height="496" alt="Screenshot 2026-08-04 at 3 35 58 PM" src="https://github.com/user-attachments/assets/dab6ab85-8ca5-42f3-927d-ca8476a861f4" />
<img width="408" height="356" alt="Screenshot 2026-08-04 at 3 37 43 PM" src="https://github.com/user-attachments/assets/cebfb0fe-7e9f-4fd6-9b0d-fe67920d3267" />
<img width="324" height="322" alt="Screenshot 2026-08-04 at 3 38 06 PM" src="https://github.com/user-attachments/assets/d3d94453-ad75-4b91-9aa3-b316b7d03674" />
<img width="687" height="603" alt="Screenshot 2026-08-04 at 3 38 18 PM" src="https://github.com/user-attachments/assets/623fff95-2967-4266-8eff-3aa4ac5f2640" />
<img width="466" height="415" alt="Screenshot 2026-08-04 at 3 38 28 PM" src="https://github.com/user-attachments/assets/b76cadf5-7b7f-473b-8912-2e5423c3d361" />
<img width="670" height="494" alt="Screenshot 2026-08-04 at 3 38 37 PM" src="https://github.com/user-attachments/assets/69b55493-615b-4951-94ac-4b7cba1979d2" />
<img width="428" height="559" alt="Screenshot 2026-08-04 at 3 38 47 PM" src="https://github.com/user-attachments/assets/bda7f481-867d-4c47-adda-58de083349d5" />


---

## June 22: Design Phase: Vision Head, Power Routing & Scratch-Build Rework
**Hours: 4**

- Switched from off the shelf kit parts to a fully scratch built chassis and arm, and redid the CAD for cleaner, more precise geometry real brackets, fillets, and fastener holes instead of blocky placeholders.
- Designed the 3D printed pan tilt sensor head carrying the stereo camera pair (fixed baseline) with the ReSpeaker mic array disc mounted on top.
- Planned the power and wiring path: LiPo → buck converter → Pi 5 and logic, with a separate motor power rail and routing channels so no wires are left floating.
- Fixed assembly issues from the earlier draft so every part is connected and seated, with nothing detached.

<img width="299" height="297" alt="Screenshot 2026-08-04 at 3 39 04 PM" src="https://github.com/user-attachments/assets/68b160d7-bd80-42c0-ac1b-93af845a18bf" />
<img width="632" height="506" alt="Screenshot 2026-08-04 at 3 39 29 PM" src="https://github.com/user-attachments/assets/9182d421-cab2-42f8-b581-88d636956fe5" />

---

## June 23: Design Phase: Final Review & Submission
**Hours: 2**

- Finished the full design and reviewed it from all angles (iso, top, front, side) to confirm fit and clearances.
- Exported the CAD files and added them to the repository.

<img width="830" height="567" alt="Screenshot 2026-08-04 at 3 39 58 PM" src="https://github.com/user-attachments/assets/2fcf5eaf-7006-445b-b5a9-01d294963a67" />
<img width="877" height="609" alt="Screenshot 2026-08-04 at 3 40 07 PM" src="https://github.com/user-attachments/assets/ce1aba15-f97a-478d-a02d-b20d3d3f6e7e" />
<img width="702" height="684" alt="Screenshot 2026-08-04 at 3 40 17 PM" src="https://github.com/user-attachments/assets/1d1f7f72-9c4c-4932-ace6-e1cdf7cadfc1" />
<img width="896" height="560" alt="Screenshot 2026-08-04 at 3 40 25 PM" src="https://github.com/user-attachments/assets/07a774b1-7931-4bfd-b752-0860b32c2602" />
<img width="732" height="678" alt="Screenshot 2026-08-04 at 3 40 35 PM" src="https://github.com/user-attachments/assets/5d040321-c414-45fe-bd77-74fbf9663e57" />

---

**Total hours: 15**
