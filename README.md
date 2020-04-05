RaspberryPi-GPIOClass-v1
=================================

Author: Hussam Al-Hertani

Description: The GPIOClass C++ class enables the Raspberry Pi its onboard GPIOs via the sysfs interface. 

============================================================================================================

To build two examples natively on the Raspberry Pi: 

Example 1:
g++ -fpermissive -Wall GPIOClass.cpp GPIOtest.cpp -o outBin1

Example 2:
g++ -fpermissive -Wall GPIOClass.cpp GPIOtest2.cpp -o outBin2

In both cases make sure that the GPIOClass.h header file is in the work (RaspberryPi-GPIOClass-v1) directory.


