# SLTC_Digital_Clock_Design
**Digital Clock Project**

This project implements a working digital clock that displays the time in the format "hh:mm:ss" and the date as "yy:mm:dd". The clock is designed using a PIC16F778A microcontroller and an LM016L 16x2 character LCD display module. The project also includes four push buttons to increase and decrease the hours and minutes.
Objective

The objective of this project is to create a digital clock that accurately displays the current time and date. The clock should be easy to set and switch between 12-hour and 24-hour formats.

**Components Used**

    PIC16F778A Microcontroller: The PIC16F778A is a high-performance microcontroller used to control the digital clock's functions and display.

    LM016L 16x2 Character LCD Display Module: The LM016L display module is used to show the time and date in a readable format.

    Variable Resistor: A variable resistor is used to control voltage or current levels in the circuit.

    Resistors (10K ohm and 10 ohm): Resistors are used to limit current and provide specific resistance values in the circuit.

    Push Switches: Five push buttons are incorporated to interact with the digital clock, allowing users to adjust the time and date.

    Quartz Crystal: A quartz crystal generates precise frequencies for clock signals.

    Capacitor (22pF): Capacitors store electric charge and energy in the circuit.

**Conclusion**

The digital clock project was successfully completed, providing a reliable and accurate display of time and date. However, due to the limitations of the code execution process and the use of polling instead of interrupts, the clock has a slight lag compared to real-time clock time. Additionally, the push buttons do not multiply values, affecting certain functionalities. The project serves as a learning experience for microcontroller programming and real-time clock modules.
Note

This project is based on the code provided. To enhance accuracy and functionality, consider exploring alternative methods such as interrupt-driven code and additional button functionalities.

For more information, refer to the references listed below.

**References**

    Wikipedia - Digital Clock
    Karnaugh Maps
    Thomas L. Floyd, "Digital Fundamentals", Seventh Edition, Prentice-Hall International, Inc., 2000.
    Donald D. Givone, "Digital Principles and Designs", McGraw-Hill, 2003.
    Victor P. Nelson, H. Try Nagle, Bill D. Carroll, and J. David Irwin, "Digital Logic Circuit Analysis & Design", Prentice-Hall Englewood Cliffs.NJ.
