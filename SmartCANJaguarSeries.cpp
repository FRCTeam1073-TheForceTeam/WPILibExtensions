#include "SmartCANJaguarSeries.h"
SmartCANJaguarSeries::SmartCANJaguarSeries() {
	jagList = new vector<SmartCANJaguar*>();
}
void SmartCANJaguarSeries::Add(SmartCANJaguar* jaguar) {
	jagList->push_back(jaguar);
}

void SmartCANJaguarSeries::Add(int count, ...) {
	va_list list;
	va_start(list, count);
	for (int i = 0; i < count; i++) {
		jagList->push_back(va_arg(list, SmartCANJaguar*));
	}
	va_end(list);
}

void SmartCANJaguarSeries::Set(float value) {
	for (int i = 0; i < (int)jagList->size(); i++) {
		jagList->at(i)->Set(value);
	}
}

void SmartCANJaguarSeries::Off() {
	Set(0.0f);
}

SmartCANJaguar* SmartCANJaguarSeries::Get(int index) {
	return jagList->at(index);
}

void SmartCANJaguarSeries::ConfigureVoltageMode() {
	for (int i = 0; i < (int) jagList->size(); i++) {
		jagList->at(i)->ConfigureVoltageMode();
	}
}

void SmartCANJaguarSeries::ConfigureSpeedMode() {
	for (int i = 0; i < (int) jagList->size(); i++) {
		jagList->at(i)->ConfigureSpeedMode();
	}
}
