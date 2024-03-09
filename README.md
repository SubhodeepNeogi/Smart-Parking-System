# Overview of the Project:
# Introduction
The smart parking system aims to remove parking hazards by providing real-time monitoring and alerts to authorities. It also enables efficient tax calculation by automating payment collection based on actual parking duration. User can check the available slots advance using a mobile app or web interface. 
# Objective
The objective of implementing a smart parking system is to address the parking challenges faced in metropolitan cities by providing real-time monitoring and alerts
to authorities. The system aims-  

i. To enable efficient tax calculation by automating payment collection based on actual parking duration.

ii. Allowing users to check for available slots in advance using a mobile app or web interface.

iii. To reduce fuel consumption and decrease pollution in urban areas.

Thereby contributing to the overall economy of the country.

# Approach:
# For Regular parking:
There will be two hall sensors, one near the outside of the entry gate and one near the inside of the entry gate. If the outside hall sensor detects a presence of a car, and at least one parking slot is empty, the entry gate will open. The car will enter and be sensed by the inside hall sensor, and then the entry gate will close. An RFID scanner will scan the car and enter its ID and entry time into the database. A timer
will start for the respective car until it reaches its designated slot within a specific timeframe. If the car fails to do so, a buzzer will alert the staff. If a car parks in a misaligned manner, in that case the buzzer will alert to notify the driver of the incorrect parking. There will be hall sensors in the parking slots that will detect when a car leaves a slot, and another timer will start. If the car does not come to the inside hall sensor of the exit gate within a specific time, the buzzer will alert again. Another RFID will scan the car and search the entry details to give the exit time and fetch the details and remove them from the database. Based on the duration of occupying the parking slot, the fare will be calculated efficiently. After successful payment, the exit gate will open, and the car will exit.
# For VIP parking:
For VIP parking, an RFID sensor will recognize the car's ID at the entry gate. There will be two hall sensors, one near the outside of the entry gate and one near the inside of the entry gate. If the outside hall sensor detects a presence of a car, then an RFID will start scanning for the card. If the car's ID matches an existing database, the gate will open. After the car passes the entry gate the inside hall sensor will detect it will close the gate. There will be hall sensors in each of the parking slots that will detect the presence of the cars. This will be helpful as if there are no empty slots then the entry gate will not open regardless if entry gate sensor detects a car. Upon exit, the car will be sensed by the inside hall sensor, and the exit gate will open until the car passes the outside hall sensor, and then it will close.
# Block Diagram
![image](https://github.com/SubhodeepNeogi/Smart-Parking-System/assets/103349527/82576c49-163a-4f06-95dc-91bdeff27e4a)
# Technology Stack:
Hardware: The hardware used to develop the project is as follows.

i. Arduino – Arduino Uno and Arduino Nano have been used.

ii.  Hall sensors – A3144 Hall Effect Sensors have been used.

iii.  NodeMCU – ESP8266 is used for cloud-based application.

iv.  Motors – SG90 Micro Servo Motor have been used.

v.  RFID sensor - REES52 RFID-RC522 RF IC Card Reader Sensor is used.

Technology: The technologies that are used are

i.  IoT – For connecting all the sensors and managing protocols

ii.  Cloud – A cloud-based platform to collect and visualize the real time parking

status in a user-friendly manner.
# Target audience:
Parking authorities

i. Vehicle owners

ii.  Municipalities and city governments

iii.  Businesses located in high-traffic areas

iv.  Tourist destinations or event venues
# Uniqueness:
i.  Check the status of parking slots from anywhere by using smart phone.

ii.  Save the time of car drivers.

iii.  No wastage of space and emergency problems can be solved.

iv.  Buzzer on misaligned parking.

v.  Efficient tax calculation mechanism based on the duration of the occupancy of the slot.

vi.  Design to build a fully automated smart parking system for a new revolution.
