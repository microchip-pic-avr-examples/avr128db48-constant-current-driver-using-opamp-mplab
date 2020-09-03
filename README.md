
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Constant-Current Driver Using the Analog Signal Conditioning (OPAMP) Peripheral
<p align="left">
  <img width=800px height=auto src="images/setup.png">
</p>

A new feature introduced in the AVR® DB MCU is the Analog Signal Conditioning (OPAMP) peripheral. In this example, the OPAMP is used as a constant-current driver using a single external resistor. It can be used to drive a load such as LEDs, with constant current and not constant voltage. The OPAMP peripheral also provides the ability to adjust the current setting under firmware control. The configuration for this example can be seen in the figure above. For more information about setup and code, see the [application note](https://microchip.com/DS00003632).

## Related Documentation

* [AN3632 - Constant-Current Driver Using the Analog Signal Conditioning (OPAMP) Peripheral](https://microchip.com/DS00003632)
* [AVR128DB48 Curiosity Nano User Guide](https://www.microchip.com/DS50003037)
* [AVR128DB48 Device Page](https://www.microchip.com/wwwproducts/en/AVR128DB48)

## Software Used

* [MPLAB® X](https://www.microchip.com/mplab/mplab-x-ide) v5.40 or later
* [MPLAB® XC8 Compiler](https://www.microchip.com/mplab/compilers) v2.20 or later
* MPLABX AVR-Dx_DFP version 1.4.75 or later
* For the Atmel Studio version of this project, please go to [this repository](https://github.com/microchip-pic-avr-examples/avr128db48-constant-current-driver-using-opamp)
  
## Hardware Used

* [AVR128DB48 Curiosity Nano](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/EV35L43A)
* One resistor (value dependent on desired current)
* Load (LED, etc)

## Setup

* Connect the hardware together as seen in the schematic of the application note

## Operation
* Connect the AVR128DB48 Curiosity Nano to a computer using a USB cable
* Download the zip file or clone the example to get the source code
* Open `avr128db48-constant-current-driver-using-opamp.X` in MPLAB
* Press the make and program button to program the device
* If no tool has been chosen, a window will open, select the AVR128DB48 Curiosity Nano. Tool can also be choosen in the project settings. 

## Conclusion
After going through this example you should have a better understanding of how to set up the OPAMP peripheral as a constant current driver for a load.

