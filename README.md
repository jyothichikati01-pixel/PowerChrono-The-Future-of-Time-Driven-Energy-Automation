# PowerChrono

#📌 Project Overview

PowerChrono is an embedded-based, time-driven energy automation system designed to automatically control an electrical device according to predefined ON and OFF schedules.

The system uses an LPC2148 ARM7 microcontroller, Real-Time Clock (RTC), 16×2 LCD, 4×4 matrix keypad, and an external interrupt switch.

Users can view the current date and time, configure the RTC, and set the device ON/OFF timings through a menu-driven interface.

The project demonstrates practical implementation of Embedded C, ARM7 microcontroller programming, RTC interfacing, LCD interfacing, keypad interfacing, GPIO control, and external interrupts.

---

# 🎯 Objectives

- Display real-time clock information on a 16×2 LCD.
- Display the current day, date, month, and year.
- Allow the user to modify RTC settings.
- Allow the user to configure device ON and OFF timings.
- Automatically control the connected device according to the configured schedule.
- Provide a keypad-based menu for user interaction.
- Use an external interrupt to enter the configuration menu.
- Demonstrate real-time embedded system control using the LPC2148.

---

# ⚙️ Hardware Requirements

- LPC2148 ARM7 Microcontroller
- 16×2 LCD Display
- 4×4 Matrix Keypad
- RTC module/peripheral of LPC2148
- LED / Electrical Load
- Push Button / External Interrupt Switch
- USB-to-UART Converter / DB-9 Cable
- Power supply
- Connecting wires and development board

---

# 💻 Software Requirements

- Embedded C
- Keil µVision
- Flash Magic
- LPC2148 device support/package
- ARM7 development environment

---

# 🧠 Technologies & Concepts Used

- Embedded C
- ARM7 – LPC2148
- Real-Time Clock (RTC)
- GPIO
- 16×2 LCD interfacing
- 4×4 Matrix Keypad interfacing
- External Interrupt
- VIC (Vectored Interrupt Controller)
- Bit manipulation
- Hardware register programming
- Time-based device control

---

# 🔄 Project Working

**System Initialization** – The LPC2148 initializes the RTC, LCD, keypad, GPIO, and external interrupt.
**Time Monitoring** – The RTC continuously provides the current time and date, which are displayed on the 16×2 LCD.
**User Configuration** – The user presses the external switch to enter the menu and uses the keypad to set the RTC and device ON/OFF timings.
**Time Comparison** – The microcontroller compares the current RTC time with the programmed ON and OFF times.
**Automatic Control** – When the ON time is reached, the device is switched **ON**. When the OFF time is reached, the device is switched **OFF**.
**Continuous Operation** – After completing the scheduled control, the system continues monitoring the RTC for the next cycle.

# 📋 Menu Structure

Main Menu

1. EDIT RTC INFO
2. DEVICE
3. EXIT

RTC Configuration

1. Hour
2. Minute
3. Second
4. Day
5. Date
6. Month
7. Year
8. Exit

Device Timing Configuration

1. ON TIME
2. OFF TIME
3. EXIT

---

# 🖥️ Project Output




---

# 📁 Project Structure

PowerChrono-main/
│
├── Headerfiles/
│   ├── defines.h
│   ├── delay.h
│   ├── kpm.h
│   ├── kpm_defines.h
│   ├── lcd.h
│   ├── lcd_defines.h
│   ├── pin_connect_block.h
│   ├── pin_function_defines.h
│   ├── rtc.h
│   ├── rtc_defines.h
│   └── types.h
│
├── Sourcefiles/
│   ├── delay.c
│   ├── kpm.c
│   ├── lcd.c
│   ├── pin_connect_block.c
│   └── rtc.c
│
├── main.c
├── interrupt.c
├── set_time.c
├── Startup.s
└── README.md

---

# 🌍 Applications

- Industrial automation
- Energy management
- Smart lighting systems
- Automatic electrical scheduling
- Embedded real-time control
- Home and office automation
- Time-based device management

---

# 📌 Future Enhancements

Possible improvements include:

- Relay-based control for actual AC appliances
- Multiple device scheduling
- EEPROM-based storage of configured timings
- Improved date validation
- Multiple daily schedules
- Power consumption monitoring
- UART-based configuration
- Remote monitoring and control
- IoT connectivity

---

# ⭐ Project Summary

PowerChrono demonstrates how an ARM7-based embedded system can combine RTC, LCD, keypad, GPIO and external interrupt functionality to create a practical time-driven automation system.

The project provides hands-on experience in both hardware interfacing and embedded software development using the LPC2148 microcontroller.
