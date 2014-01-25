#include "SmartCANJaguarSeries.h"
SmartCANJaguarSeries::SmartCANJaguarSeries() : SpeedControllerSeries() {}

void SmartCANJaguarSeries::Add(SmartCANJaguar* jaguar) {
	SpeedControllerSeries::Add(jaguar);
}

void SmartCANJaguarSeries::Add(int count, ...) {
	va_list list;
	va_start(list, count);
	for (int i = 0; i < count; i++) {
		Add((va_arg(list, SmartCANJaguar*)));
	}
	va_end(list);
}

SmartCANJaguar* SmartCANJaguarSeries::Get(int index) {
	return (SmartCANJaguar*)(SpeedControllerSeries::Get(index));
}

void SmartCANJaguarSeries::ConfigureVoltageMode() {
	for (int i = 0; i < (int) speedControllerList->size(); i++) {
		((SmartCANJaguar*)speedControllerList->at(i))->ConfigureVoltageMode();
	}
}

void SmartCANJaguarSeries::ConfigureSpeedMode() {
	for (int i = 0; i < (int) speedControllerList->size(); i++) {
		((SmartCANJaguar*)speedControllerList->at(i))->ConfigureSpeedMode();
	}
}
