# ESP32 Asynchronous Wi-Fi Scanner & LED Controller

This repository contains the implementation of an asynchronous Wi-Fi network scanner system built using an ESP32 microcontroller and the OpenPLC environment. This project combines industrial automation concepts with wireless communication technology through custom C++ function block programming, allowing network scanning to run in parallel without interrupting the PLC's main control cycle.

## Key Project Features

* **Asynchronous (Non-Blocking) Scanning Architecture:** Utilizes the ESP32's processing capabilities to perform network scanning in the background. This approach resolves the blocking issues typical of standard functions, ensuring that OpenPLC control logic instructions and hardware actuation continue to execute smoothly with minimal latency.
* **Real-Time Indicator System:** Integrates responsive LED controls that provide instant visual feedback based on detected network metrics and status, bridging backend operations with direct hardware interaction.
* **Precise Baremetal Execution:** Compiled and executed at the ESP32 baremetal level, resulting in a system with extremely low memory overhead, highly efficient resource allocation, and rapid execution speeds.
* **Custom C++ Function Block Implementation:** Demonstrates a deep understanding of the OpenPLC ecosystem by establishing a modular code infrastructure that can be easily scaled or integrated into broader automation architectures.

## Technology Specifications

* **Core Hardware:** ESP32 Microcontroller (Generic Board)
* **Platform & Framework:** OpenPLC, Arduino Core Libraries
* **Programming Language:** C++ 
* **Execution Method:** Baremetal ESP32 Architecture

## Prerequisites

* **Hardware:**
  * ESP32 Development Board
  * LEDs and current-limiting resistors (e.g., 220Ω or 330Ω)
  * Jumper wires and breadboard
* **Software:**
  * [OpenPLC Editor](https://openplcproject.com/) installed on your host machine.

## Wiring Guide

Connect the LEDs to the respective GPIO pins on the ESP32 as defined in your OpenPLC hardware configuration. 
* **LED Indicator 1 (e.g., Scan Active)**
* **LED Indicator 2 (e.g., Network Found)**

## Installation & Getting Started

1. **Clone the Repository:**
2. **Open the Project:**
   * Launch the OpenPLC Editor.
   * Navigate to `File` > `Open Folder` and select the directory of the cloned repository.
3. **Review the Function Block:**
   * Inspect the custom C++ function block to ensure the Wi-Fi scanning parameters and variables align with your requirements.
4. **Compile and Upload:**
   * Click on the **Compile program for appropriate board** button in the OpenPLC Editor.
   * Select **ESP32** from the board dropdown list.
   * Select the correct COM port for your device and click **Upload**.

## Usage

Once the program is successfully uploaded to the ESP32:
1. Power the ESP32 via a USB cable or an external power supply.
2. The asynchronous Wi-Fi scanning function will automatically initialize in the background.
3. Observe the LED indicators; they will dynamically change states in real-time based on the network scanning results, demonstrating that the main PLC execution cycle is running without interruption.

## Demonstration

Watch the system demonstration in action:
* **https://youtu.be/sphYSSkl_HM?si=-BEEyqNg6r8MEKi9**
