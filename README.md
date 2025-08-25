🚪 ENTER SYSTEM – Smart Door Access System

A microcontroller-based access control system built using ATmega32, fully developed with custom drivers for all peripherals. The project was part of the Microcontroller-Based Systems Track (NTI Summer Internship), focusing on low-level embedded systems programming.

The system provides secure door access through keypad passwords, RFID cards, and remote IoT control, with support for over-the-air firmware updates (FOTA) and real-time monitoring.

📑 Table of Contents

System Overview

Access Methods

Software Architecture

Drivers Implemented

Technologies & Tools Used

Development Tools

Features

Future Enhancements


🔧 System Overview

🧠 Main Controller: ATmega32

All drivers written from scratch (GPIO, UART, I2C, SPI, Timers, External Interrupts, ADC).

Controls the door lock system and validates authentication inputs.

Communicates with external modules (RFID, Keypad).

🚪 Door Control Unit

Relay or Motor Driver for door lock/unlock mechanism.

Keypad for password entry.

RFID reader for card-based access.

LCD display for system status & user prompts.

📡 Communication Layers

UART: ATmega32 ↔ .

SPI/I2C: Peripheral communication.

📱 Access Methods

Password Entry (Keypad + LCD)

User enters password via keypad.

System validates → unlocks door on success, displays error on failure.

RFID Authentication

RFID card presented to reader.

ATmega32 checks stored IDs.

Unlocks if valid.

⚙️ Software Architecture

ATmega32 with custom drivers (no HAL/Arduino libraries).

Modular layered design:

MCAL → GPIO, UART, SPI, I2C, Timers, ADC, EXTI.

HAL → Keypad, LCD, RFID, Relay Driver.

Service Layer → Access validation, FOTA handler, authentication logic.

FreeRTOS not used (bare-metal design, cooperative scheduling).

🛠️ Drivers Implemented

MCAL Drivers:

GPIO

UART

SPI

I2C

Timers (PWM, Delay, Capture/Compare)

ADC

External Interrupts

HAL Drivers:

Keypad

LCD (16x2)

RFID Module (UART-based)

Relay/Motor Driver

Bluetooth (HC-05)

🧰 Technologies & Tools Used
Category	Tools/Hardware
Microcontrollers	ATmega32
Sensors & Modules	RFID Reader, Keypad, LCD, Relay
Protocols	UART, SPI, I2C, MQTT
👨‍💻 Development Tools

Atmel Studio / Microchip Studio

Proteus (Simulation & Circuit Design)

Visual Studio Code


🔐 Features

Multiple authentication methods (Password, RFID, Mobile App).

Custom driver development (no external libraries).

Secure and modular software architecture.

Wireless firmware updates (FOTA) for ATmega32.

Real-time LCD feedback.
