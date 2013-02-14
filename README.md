#WPILib Extensions
This library is a set of C++ classes that add more functionality to the FRC WPI Library. These classes are used by [FRC Team 1073: The Force Team](http://theforceteam.com) in our [Ultimate Ascent Code](https://github.com/FRCTeam1073-TheForceTeam/robot13), but could probably be used to save you time when programming.

The following Document explains all of our tools and the functionality they will add to your robot, as well as how to use them. **Don't waste time trying to work with the stock library, when you can get some great free help here from Team 1073 :)**


##Usage
To use any of these tools, simply include the global header file WPILibExtensions.h with the following code:

```	
	#include "WPILibExtensions/WPILibExtensions.h"
```

*Note that this statement assumes that the WPILibExtensions directory was cloned in the root of your WindRiver project.*


These classes extend off items in Brad Miller's `WPILib` to add even more functionality to your robot codebase. We hope that they will be of help to you! If you ever need help, or want to see a feature added, you're welcome to talk over this github repository, or to code the feature in yourself!

##Contents:
**[Tools:](#Tools)**
These tools provide access to more functionality with the WPILib.

*	[LimitSwitch](#LimitSwitch) - Easily integrate Digital Limit Switches into code without worrying about equaling a return value
*	[SmartJoystick](#SmartJoystick) - Gain full control of your joysticks by adding cubic and extreme algorithims, across all axis. Functionality like axis inversion is can be added in easily. Functions to get the fickle Hat axis on a joystick are also included.
*	[Stallable](#Stallable) - Easily add Stall Detection to a `CANJaguar` and `AnalogEncoder` so you don't burn out your motors!

**[Commands:](#Commands)**
These commands provide quick utility features to make debugging easier.

*	[InterruptSubsystem](#InterruptSubsystem) - Takes a pointer to a WPILib `Subsystem` and interrupts all WPILib `Command`s that are using it.
*	[PrintStallData](#PrintStallData) - Prints to Standard Out voltage data regarding a device that is an implementation of [Stallable](#Stallable)


<a name = "Tools"/>
##Tools

<a name = "LimitSwitch"/>
###LimitSwitch
Simple inline boolean function for doing a quick check for a Limit Switch being pressed. No more confusing logic with the pull up resistor, `==0', `==1`, etc. Instead, just call `LimitPressed(DigitalInput* input)`

	//simple check for limit Switch Press
	DigitalInput* limitSwitch = new DigitalInput(1);
	bool isPressed = LimitPressed(limitSwitch);
	
<a name = "SmartJoystick"/>	
###SmartJoystick
A class that extends the `Joystick` class. Provides for a ton of extra functionality! Here's how to make one.

	//here's a normal WPILib Joystick
	Joystick* operatorStick = new Joystick(1); //basic functionality joystick///
	//simply add the word Smart in front of Joystick and you're all set
	SmartJoystick* operatorStick = new SmartJoystick(1); //lots of functionality, fully compatible with the WPILib	as well!
	
####Configurable JoystickModes Modes
A `SmartJoystick` can be set to three modes `normal`, `extreme` and `cubic`. These modes alter the values that `SmartJoystick::GetX()` and `SmartJoystick::GetY()` return. *Note that all Joystick Modes supprort a small Dead Zone where Joystick input is ignored. This allows for the sticks to remain relatively close to a neutral position irl, but are still neutral in the software*
#####Normal
A `SmartJoystick` in the `normal` mode returns regular `Joystick` when `SmartJoystick::GetX()` and `SmartJoystick::GetY()` are called.

	operatorStick->SetJoystickMode(SmartJoystick::normal);
	float normalx = operatorStick->GetX(), normaly = operatorStick->GetY();
#####Extreme
A `SmartJoystick` in the `extreme` mode returns a full reading if the Joystick is outside of the Dead Zone. This allows operators to quickly ramp up the value of a Joystick while nudging it only slightly. Extremely useful for making a robot sprint across the field really fast.
	
	operatorStick->SetJoystickMode(SmartJoystick::extreme);
	//stick is only nudged forward just a little bit…
	float extremey = operatorStick->GetY();	// equals 1.0
	//stick is only nduged backwards just a little bit…
	extremey = operatorStick->GetY();			//equals -1.0
#####Cubic
This mode is a favorite with some of our drivers. It allows Joystick input to be scaled by a cubic factor to allow for a smoother acceleration rate as a Joystick is moved further and further forward or back.
####Invertable Axis
Quickly invert a `SmartJoystick	` Axis without having to change values all over your code. Call invert once, and your `SmartJoystick` inversion will be on any call to the Joystick's axis.
	
	float y = operatorStick->GetY();	//Get the Y value... oh no, it's upside down!!!
	operatorStick->InvertYAxis();	//Simple Call to invert the Axis, works on X, Y, and Z
	y = operatorStick->GetY();	//The Y value is know -1 times what it was earlier
####Hat Axis
Many Joysticks have a hat on the top of the Joystick, Generally these live on Axis 5 and 6 of the Joystick. With `SmartJoystick` it's easy to get their values.

	//no more dealing with Axis Parameters
	float hatx = operatorStick->GetHatX();
	float haty = operatorStick->GetHatY();

<a name = "Stallable"/>	
###Stallable
Abstract class to detect a stall in an Encoder or other voltage source. Simply extend off this class and implement `float Stallable::GetVoltageSource() = 0` to establish an object as a `Stallable`. From there, call `void Stallable::ProcessVoltageData()` to read a voltage from the implemented float method, and `bool Stallable::IsStall()` to check for a stall.
####Implementations:
#####StallableAnalogEncoder
A `Stallable` that extends off of `AnalogChannel` to add stall detection to common Analog Encoders
#####StallableCANJaguar
A `Stallable` that extends off of `CANJaguar` to add stall detection to CANJaguars with an encoder plugged into them.
#####Add your own!
*Simply extend Stallabe and implement* `float Stallable::GetVoltageSource() = 0`

<a name = "Commands"/>
##Commands
WPILib `Command`s that make debugging and code manipulation easier.

<a name = "InterruptSubsystem"/>
###InterruptSubsystem
Takes a pointer to a WPILib `Subsystem	` and uses `Subsystem::Requires(Subsystem*)` to interrupt all WPILib `Command`s that use that `Subsystem`.

	Subsystem* driveTrain = new Subsystem("DriveTrain"); //basic subsystem
	InterruptSubsysem* command = new InterruptSubsystem(driveTrain);
	command->Start();	//Interrupts all Subsystems that use DriveTrain

<a name = "PrintStallData"/>
###PrintStallData
Prints out the collected voltage data of a `Stallable` device

	StallableCANJaguar* leftMotor = new StallableCANJaguar(1); //here's a motor
	PrintStallData* command = new PrintStallData(leftMotor); //make command
	command->Start(); //Starts command, data will be printed.

