# Thermostat

A thermostat is a device used to regulate and manage the temperature of a system, typically used in heating, ventilation, and air conditioning (HVAC) systems for homes, workplaces, and other buildings. It works by detecting the environment's current temperature and comparing it to a predetermined temperature known as the "setpoint." The thermostat adjusts its settings to maintain the appropriate temperature based on this comparison.


# Arduino UNO

Arduino Uno is a popular microcontroller board based on the ATmega328P microcontroller. Arduino Uno microcontroller with 32KB of flash memory for programme storage, 2KB of SRAM for data storage, and 1KB of EEPROM for non-volatile storage. It includes 14 digital input/output pins, of which 6 are PWM outputs, allowing you to connect a variety of sensors, actuators, and other electronic parts.Six analogue input pins on the Arduino Uno, labelled A0 through A5, can be used to read analogue voltage levels coming from sensors. A USB connection or an external DC power supply (7–12V) can be used to power the board. It contains an internal voltage regulator that delivers a consistent 5V supply to the parts. The Arduino Uno may be easily programmed and communicated with via a USB cable when it is linked to a computer. The software known as Arduino IDE is used to develop, compile, and upload code to the Arduino Uno board. It is simple to use and appropriate for novices. Arduino may be used by persons with little to no programming knowledge because to the C/C++ programming language that it utilises. The development process is made simpler by Arduino's extensive library collection, which offers pre-written routines for a variety of activities. The hardware and software for the Arduino Uno are both available for public usage.


# LCD Display

A 16x2 LCD display is a common type of alphanumeric liquid crystal display used in various electronic projects and devices. It has 16 columns and 2 rows of characters, allowing it to display up to 32 characters at a time. Each character position can display numbers, letters, and other custom symbols. Many 16x2 LCD displays come with a built-in LED backlight that can be controlled separately to enhance visibility in low-light conditions.  Each character is usually made up of a 5x8 pixel matrix, allowing for simple character-based graphics. They are widely used with Arduino and other microcontrollers, as there are libraries available that simplify the programming and interfacing process.


# LM35

The LM35 is a popular analog temperature sensor used to measure temperature in electronic systems. Main characteristics are:
1. The LM35 sensor is capable of taking precise readings in the -55°C to +150°C range. It is excellent for a variety of industrial and consumer applications due to its wide temperature range.
2. Analogue output voltage that is linearly proportional to the temperature being sensed is provided by the LM35. The output voltage varies by 10 mV (0.01V) for every 1°C change in temperature.
3. The sensor has low self-heating, which means that even when it produces heat on its own, the accuracy of temperature measurements is not severely impacted.
4. Because of its low power operation, the LM35 is appropriate for battery-operated devices and other applications where power efficiency is critical.


# Working of digital thermostat:

1. Used LCD display of 16*2 to display the current room temperature and also tells whether the temperature needs to be increased or decreased.
2. Used of arduino uno to assemble all the components.
3. LM35 sensor used to sense the current room temperature.
4. When the temperature is known, temperature is compared to the setpoint(taken as 22.5 deg C).
5. If the temperature is greater then setpoint, LCD displayes that the temperature decreased by the difference of the two temperatures.
6. If the temperature is lesser then setpoint, LCD displayes that the temperature increased by the difference of the two temperatures.
7. If the temperature and setpoint are equal, LCD displayes that the temperature is normal.