# PowerChrono

📌 Project Overview

PowerChrono is an embedded-based, time-driven energy automation system designed to automatically control an electrical device according to predefined ON and OFF schedules.

The system uses an LPC2148 ARM7 microcontroller, Real-Time Clock (RTC), 16×2 LCD, 4×4 matrix keypad, and an external interrupt switch.

Users can view the current date and time, configure the RTC, and set the device ON/OFF timings through a menu-driven interface.

The project demonstrates practical implementation of Embedded C, ARM7 microcontroller programming, RTC interfacing, LCD interfacing, keypad interfacing, GPIO control, and external interrupts.

---

🎯 Objectives

- Display real-time clock information on a 16×2 LCD.
- Display the current day, date, month, and year.
- Allow the user to modify RTC settings.
- Allow the user to configure device ON and OFF timings.
- Automatically control the connected device according to the configured schedule.
- Provide a keypad-based menu for user interaction.
- Use an external interrupt to enter the configuration menu.
- Demonstrate real-time embedded system control using the LPC2148.

---

⚙️ Hardware Requirements

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

💻 Software Requirements

- Embedded C
- Keil µVision
- Flash Magic
- LPC2148 device support/package
- ARM7 development environment

---

🧠 Technologies & Concepts Used

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

🔌 System Architecture

             +----------------------+
             |      4×4 Keypad      |
             +----------+-----------+
                        |
                        v
             +----------------------+
             |       LPC2148        |
             |      ARM7 MCU        |
             +----+----+----+-------+
                  |    |    |
                  |    |    +----------------+
                  |    |                     |
                  |    v                     v
                  |  External            LED / Device
                  |  Interrupt             Control
                  |
                  v
             +----------+
             |   RTC    |
             +----------+
                  |
                  v
             +----------+
             | 16×2 LCD |
             +----------+

---

🔄 Project Working

1. System Initialization

When the system starts:

- LCD is initialized.
- Keypad is initialized.
- RTC is initialized.
- External interrupt is configured.
- LED/device control GPIO is configured.

2. RTC Monitoring

The LPC2148 continuously reads:

- Hour
- Minute
- Second
- Day
- Date
- Month
- Year

The information is displayed on the LCD.

3. Setting Device Timings

Using the keypad, the user can configure:

Device ON Time

Hour : Minute : Second

Device OFF Time

Hour : Minute : Second

The system stores these values and compares them with the current RTC time.

4. Automatic Device Control

The LPC2148 compares the current time with the programmed ON/OFF timings.

When the configured condition is satisfied:

ON condition → Device/LED ON
OFF condition → Device/LED OFF

This provides automatic time-based control without continuous manual operation.

5. External Interrupt

An external switch is connected to the EINT0 interrupt.

When the switch is pressed:

Switch Press
     ↓
External Interrupt
     ↓
EINT0 ISR
     ↓
Configuration Menu
     ↓
User edits settings
     ↓
Normal operation resumes

---

📋 Menu Structure

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

🖥️ LCD Display

During normal operation, the LCD displays the RTC information.

Example:

12:30:45    MON
19/09/2026

When device timing information is viewed:

OT:08:30:00
OF:18:30:00

The device status is also represented on the LCD.

---

📁 Project Structure

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

📂 File Description

File| Description
"main.c"| Main application logic, RTC monitoring and device control
"interrupt.c"| External interrupt service routine
"set_time.c"| RTC and device ON/OFF configuration menus
"Startup.s"| ARM startup/initialization code
"rtc.c"| RTC initialization, reading, writing and display functions
"lcd.c"| LCD initialization and display functions
"kpm.c"| Matrix keypad scanning and input handling
"delay.c"| Delay functions
"pin_connect_block.c"| LPC2148 pin configuration
"*.h"| Function declarations, macros, definitions and data types

---

🔧 Key Features

⏰ Real-Time Scheduling

The system uses the LPC2148 RTC to perform time-based device control.

📟 LCD Interface

A 16×2 LCD provides real-time information and user menus.

🔢 Keypad Interface

A 4×4 matrix keypad allows the user to enter configuration values.

⚡ Automatic Device Control

The connected LED/device is automatically controlled according to programmed timings.

🚨 External Interrupt

An external switch generates an interrupt and provides access to the configuration menu.

🧩 Modular Programming

The project separates LCD, keypad, RTC, delay, GPIO and interrupt functionality into different source and header files.

---

🚀 How to Build and Run

Step 1 – Open the Project

Open the project in Keil µVision with LPC2148/ARM7 device support installed.

Step 2 – Add Source Files

Make sure the following files are included in the project:

main.c
interrupt.c
set_time.c
Startup.s

Sourcefiles/
    delay.c
    kpm.c
    lcd.c
    pin_connect_block.c
    rtc.c

Step 3 – Configure Header Files

Make sure the compiler include path contains:

Headerfiles/

Step 4 – Build the Project

Compile and build the project in Keil µVision.

Step 5 – Generate HEX File

After a successful build, generate the required ".hex" file.

Step 6 – Flash the LPC2148

Use Flash Magic or a compatible programming tool to download the HEX file into the LPC2148.

Step 7 – Test the System

After programming:

1. Power ON the hardware.
2. Observe the RTC information on the LCD.
3. Set the required device ON time.
4. Set the required device OFF time.
5. Observe automatic device control.
6. Press the external interrupt switch to enter the configuration menu.

---

🧪 Example Use Case

Suppose the user configures:

Device ON  : 08:30:00
Device OFF : 18:30:00

The system continuously monitors the RTC.

During the configured operating period, the LPC2148 activates the device output.

After the programmed OFF condition is reached, the device output is deactivated.

This concept can be extended to applications such as:

- Automatic lighting
- Energy management
- Industrial equipment scheduling
- Office automation
- Smart electrical control
- Time-based embedded systems

---

🌍 Applications

- Industrial automation
- Energy management
- Smart lighting systems
- Automatic electrical scheduling
- Embedded real-time control
- Home and office automation
- Time-based device management

---

🎓 Learning Outcomes

This project provided practical exposure to:

- ARM7 LPC2148 microcontroller programming
- Embedded C programming
- RTC programming
- LCD interfacing
- Matrix keypad interfacing
- GPIO programming
- External interrupt handling
- VIC configuration
- Hardware register manipulation
- Modular embedded software development

---

👩‍💻 Project Type

Embedded Systems / ARM7 / Embedded C Project

Microcontroller: LPC2148 ARM7

Programming Language: Embedded C

Development Environment: Keil µVision

---

📌 Future Enhancements

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

📜 License

This project is intended for educational and demonstration purposes.

---

⭐ Project Summary

PowerChrono demonstrates how an ARM7-based embedded system can combine RTC, LCD, keypad, GPIO and external interrupt functionality to create a practical time-driven automation system.

The project provides hands-on experience in both hardware interfacing and embedded software development using the LPC2148 microcontroller.
