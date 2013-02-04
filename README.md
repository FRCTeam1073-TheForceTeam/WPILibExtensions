#WPILib Extensions
A set classes that add more functionality to the FRC WPI Library. These classes are used by [FRC Team 1073: The Force Team](http://theforceteam.com) in our [Ultimate Ascent Code](https://github.com/FRCTeam1073-TheForceTeam/robot13), but could probably be of use to other teams.

Please use as you see fit.

##Usage
To use any of these tools, simply include the global header file WPILibExtensions.h with the following code:

```	
	#include "WPILibExtensions/WPILibExtensions.h"
```

Note that this statement assumes that the WPILibExtensions directory was cloned in the root of your WindRiver project.

Additionally, to use the Commands included with this library, you must have a WPILib Main Robot class in the root of your project. In this case, I use ``Robot.h``

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

###Print Stall Data
WPILib Command for pulling debug data off of a Stallable object
####Usage:
```
	Command* test = new PrintStallData(Stallable* stallable);
	//prints out data and command exits 
```

####Usage:
```
	//simple boolean check for stall
	if(yourAnalogEncoder->IsStall()) //...
```
###SmartJoystick
Extension class of the Joystick for axis inversion. Other features will be added as we need them.