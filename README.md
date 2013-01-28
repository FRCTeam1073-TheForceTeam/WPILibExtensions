#WPILib Extensions
A set classes that add more functionality to the FRC WPI Library. These classes are used by FRC Team 1073: The Force Team in our [Ultimate Ascent Code](https://github.com/FRCTeam1073-TheForceTeam/robot13), but could probably be of use to other teams.

Please clone and/or fork as you see fit, good luck in the competition.

##Usage
To use these tools, simply include the global header file WPILibExtensions.h whith the following code:
```	
	#include "WPILibExtensions/WPILibExtensions.h"`
```
Note that this statement assumes that the WPILibExtensions directory was cloned in the root of your WindRiver project.

##Features
###LimitSwitch
Class to represent a limit switch digital IO. No more `== 1` or `== 0`, instead a simple `IsPressed()` Method.

####Usage:
```
	//simple check for limit Switch Press
	if(yourLimitSwitch->IsPressed()) //...
```
###Stallable Jaguar
Extension of the Jaguar class to include built in stall detection. Uses the included abstract base class Stallable

####Usage:
```
	//simple boolean check for stall
	if(yourJaguar->IsStall()) //...
```
###Stallable Analog Encoder
Extension of the Analog Channel class to include built in stall detection. Uses the included abstract base class Stallable.

####Usage:
```
	//simple boolean check for stall
	if(yourAnalogEncoder->IsStall()) //...
```
###SmartJoystick
Extension class of the Joystick for inversion. Other features, including scaling, we plan on adding in the future.