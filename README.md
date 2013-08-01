halherta-RaspberryPi-GPIOClass-v1
=================================

Author: Hussam Al-Hertani

Description: The GPIOClass C++ class enables the Raspberry Pi its onboard GPIOs via the sysfs interface. 

============================================================================================================

For more information please visit:  http://hertaville.com/2013/07/24/interfacing-an-spi-adc-mcp3008-chip-to-the-raspberry-pi-using-c/

============================================================================================================

To build two examples natively on the Raspberry Pi: 

Example 1:
g++ -fpermissive -Wall GPIOClass.cpp GPIOClassTest.cpp -o outBin1

Example 2:
g++ -fpermissive -Wall GPIOClass.cpp GPIOClassTest2.cpp -o outBin2

In both cases make sure that the GPIOClass.h header file is in the work directory.


