
<p align="center">
  <img src="Images/eyealert-logo.png" height=120>
</p>

<p align="center">
  <b> Gunvir Ranu | Katarina Chiam | Ken Shi | Spencer Ball </b>
</p>

eye**alert** is a safety glasses compliance & redundancy system that prompts users to put on their safety glasses when they forget to wear them. This system integrates regular safety glasses with 3 modules and a notification system the reminds users with visual and sensory cues. This significantly decreases the risk of danger caused by accidental carelessness in workspaces and makes it much easier for staff to check up on users. Despite being originally designed for the Toronto Tool Library Makerspace, it can be easily be used in a variety of locations due to its low-cost and adaptability.

<p align="center">
  <img src="Images/glasses.png" height=600>
</p>

## Implementation
The eye**alert** safety glasses are wirelessly connected to a central hub. If the glasses detect that they are not being worn correctly, a signal is sent to an external light on a wall to visually stimulate the user and staf and vibration on the glasses acts as sensory stimuli to the user directly. The notifications turn off when the user puts the safety glasses back on. After the user is finished, they simply return the eye**alert** glases to the hub for recharging.

## Objectives
1. **Reduce** frequency and duration of **dangerous situations** in the workspace.
2. **Shift responsibility** from ensuring safety from users and staff to the system.

## Poster
![](Images/poster.png)

## Motivation
Safety glasses play an important role in ensuring people’s safety in any workspace, as eye injuries can be permanently debilitating and costly. Although safety glasses are one of the most basic safety equipment, it is also one of the easiest ones to forget. According to the Centers for Disease Control and Prevention, 90% of eye injuries could have be prevented by the proper use of safety glasses. Clearly, it is imperative that safety glasses are worn in any situation where eye safety can be compromised.

## Key Features

### Frictionless
As the design builds on standard safety glasses, users would experience minimal changes in adapting to the new system, as there is virtually no change to the current process of using safety glasses. The process of usage is incredibly intuitive and should be easy to adopt for users of any experience level.

### Adaptability
In most situations, safety glasses are required to be worn in the workspace. This design works with any environment in any workspace as it is not dependant on specific tools.

### Installability
As a result of an easy-to-attach system and low number of components, permanent modifications are not required. This allows for simple and straightforward repair and replacement, a great advantage for smaller, independant workspaces.

## Brief Detailed Design

#### Hub
* The Hub is to be placed in a location with easy access
* At the Toronto Tool Library, the Hub will be placed in the same location as the current safety glasses

#### Ergonomics
* To ensure frictionless usage while wearing, components were chosen to minimize negative impact on the user’s experience
* All components are in an incredibly small form factor to reduce the change in mass and weight distribution to keep the "feel" of glasses the the same

#### Sensor
* Capacitive sensor located under nosepiece is used to detect if wearing glasses
* Chosen due to simplicity, reliability and cost
* Extensive verification and validation conducted on the placement of sensor on the frame

#### Communications
* RF (radio frequency) transreceiver used to communicate between the safety glasses and hub
* Requirements of data transmission are low-bandwidth, and very low cost and power consumption

#### Notifications
* Extensive research on human stimuli to determine the best method of alerting users
* Cannot alert the user recklessly as they are working with dangerous and high-power tools
* A light for users and staff, and a vibration motor are used

#### Battery
* Hub recharges battery when the glasses are not being used
* 150 mAh LiPo battery on the glasses used to power the system
* Theoretical calculations and preliminary testing show that the battery life is longer than the usual opening hours

#### Electronics
* Low-power and cost AVR microcontroller (ATtiny85) used for control on the safety glasses
* Combined with RF, allows for minimal power consumption, greatly extending battery life
