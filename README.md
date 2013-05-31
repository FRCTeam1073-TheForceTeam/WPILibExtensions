#WPILib Extensions
This library is a set of C++ classes that add more functionality to the FRC WPI Library. These classes are written used by [FRC Team 1073: The Force Team](http://theforceteam.com) in our [Ultimate Ascent Code](https://github.com/FRCTeam1073-TheForceTeam/robot13), and could probably be used to save you time and sanity when programming yours.

The following Document explains all of our tools and the functionality they will add to your robot, as well as how to use them. **Don't waste time fiddling with the stock library, when you can get some great free help here from Team 1073 :)**


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

*	[CommonFunctions](#CommonFunctions) - Not much to say here, just contains some inline math functions that we'd usually otherwise end up writing at like five different spots in our code.
*	[LimitSwitch](#LimitSwitch) - Easily integrate Digital Limit Switches into code without worrying about equaling a return value
*	[SmartCANJaguar](#SmartCANJaguar) - Contains functions for manipulating the mdoe a CANJaguar is in (*which is usually done in several calls*), and provides Stall Detection and Global Inversion. Very Useful.
*	[SmartGyro](#SmartGyro) - A class to manipulate the values that a Gyro returns. Globally get angle measurements represented however you want.
*	[SmartJoystick](#SmartJoystick) - Gain full control of your joysticks by adding cubic and extreme algorithims, across all axis. Functionality like axis inversion is can be added in easily. Functions to get the fickle Hat axis on a joystick are also included.
*	[Stallable](#Stallable) - Easily add Stall Detection to a `CANJaguar` and `AnalogEncoder` so you don't burn out your motors!
*	[IREncoder](#IREncoder) - A class inhereting from DigitalInput representing an encoder made from an Infrared Emmiter and Detector and a peice of reflective tape. Calculates rpm using high speed inturrupts. 

**[Commands:](#Commands)**
These commands provide quick utility features to make debugging easier.

*	[InterruptSubsystem](#InterruptSubsystem) - Takes a pointer to a WPILib `Subsystem` and interrupts all WPILib `Command`s that are using it.
*	[PrintStallData](#PrintStallData) - Prints to Standard Out voltage data regarding a device that is an implementation of [Stallable](#Stallable)


<a name = "Tools"/>
##Tools

<a name = "CommonFunctions"/>
###Common Functions
Basic math functions and constants that are implemented as macros.

<a name = "LimitSwitch"/>
###LimitSwitch
Simple inline boolean function for doing a quick check for a Limit Switch being pressed. No more confusing logic with the pull up resistor, `==0`, `==1`, etc. Instead, just call `LimitPressed(DigitalInput* input)`

	//simple check for limit Switch Press
	DigitalInput* limitSwitch = new DigitalInput(1);
	bool isPressed = LimitPressed(limitSwitch);

<a name = "SmartCANJaguar"/>
###SmartCANJaguar
A class that provides some useful functions to `CANJaguar`
####Inversion
`SmartCANJaguar`s can easily be inverted by calling the method `Invert` on them. This usually has to happen because motors are mounted or wired differently than the code thinks they are. Usuaully we'd multiply whatever we set by `-1` but this creates for sloppy code. **Inverted `SmartCANJaguar`s provide for global support and keeps the code clean**

	SmartCANJaguar* rightDrive = new SmartCANJaguar(2);	//make jag
	rightDrive->Invert();	//Invert Jag
	bool check = rightDrive->IsInverted();	//optional debug check to see if the Jag is inverted
	rightDrive->Invert();	//put it back

	//or, invert a SmartCANJaguar right in its constructor
	SmartCANJaguar* leftDrive = new SmartCANJaguar(1, true);	//constructed with inversion
	SmartCANJaguar* rightDrive = new SmartCANJaguar(2, fakse);	//constructed without inversion
	SmartCANJaguar* discLauncher = new SmartCANJaguar(3);		//constructed without inversion


####Easily change `CANJaguar` Modes
When using a `CANJaguar`, you often have to tell the cRIO how it will be used. This usually involves calling several `CANJaguar` functions in order to tell it you want to set it based off of encoder readings (`CANJaguar::kSpeed`), or by applying a percantage of allocatable voltage (`CANJaguar::kVoltage`). With `SmartCANJaguar` these modes can be easily applied. (*note that encoder configuration varies from Jaguar to Jaguar, and you might have to adapt these calls to match your specific hardware configuration...*)

	SmartCANJaguar* leftDrive = new SmartCANJaguar(1);	//make jag
	leftDrive->ConfigureSpeedMode();	//speed mode
	//oh, no! an encoder failed - let's fall back to voltage
	leftDrive->ConfigureVoltageMode(); 

####Stall Detection
`SmartCANJaguar`s implement [Stallable](#Stalable) so they can easily be checked for Stall Detection. For more information on `Stallable` [click here](#Stallable).

	//pseduo code for stall detection
	SmartCANJaguar* leftDrive = new SmartCANJaguar(1);
	leftDrive->Set(1000.0);	//drive
	while(!leftDrive->IsStall()){
		leftDrive->ProcessVoltageData();	//update Stallable
	}
	leftDrive->Set(0.0);	//turn off motor, we have a stall
 
####Check if the CANJaguar exists on the 2CAN Bus
To do a diagnostic check to see if the 2CAN Bus can reach your CANJaguar hardware, just call the boolean method `SmartCANJaguar::ExistsOnBus()`

	SmartCANJaguar* leftDrive = new SmartCANJaguar(1);
	if(leftDrive->ExistsBus()){
		printf("This exists\n");
	}
	else{
		printf("This doesn't exist\n");
	}

<a name = "SmartGyro"/>
###SmartGyro
The `WPILib Gyro` class returns angle measurements in Radians/pi. This is useful for counting how many pis you have, but we don't like this form of measuring angles. When constructing a `SmartGyro` it will behave just like a `Gyro` but the data it returns can be manipulated to return degrees or radians, as well. By having an extension class to manipulate these values, you are warranted security, as every call to `SmartGyro::GetAngle` will return the same value, as opposed to manipulating what `Gyro::GetAngle` returns throughout your code.

####Changing Gyro Mode
	SmartGyro* gyro = new SmartGyro(1);
	float angle = gyro->GetAngle();	//default
	gyro->SetGyroMode(radians);
	angle = gyro->GetAngle();	//now in radians
	gyro->SetGyroMode(degrees);
	gyro->GetAngle();	//now in degrees
	gyro->SetGyroMode(radiansOverPi);	//back to default


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
CANJaguars can implement `Stallable` as well. We provide a class that does this with `SmartCANJaguar`, if you don't want to use that class, simply implement `Stallable::GetVoltageSource()` by returning `CANJaguar::GetOutputVoltage()`

Want more Stall Detection?	
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

