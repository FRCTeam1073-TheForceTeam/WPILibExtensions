#include "SpeedControllerSeries.h"

void SpeedControllerSeries::Add(SpeedController* speedController) {
	speedControllerList->push_back(speedController);
}

void SpeedControllerSeries::Add(int count, ...) {
	va_list list;
	va_start(list, count);
	for (int i = 0; i < count; i++) {
		speedControllerList->push_back(va_arg(list, SpeedController*));
	}
	va_end(list);
}


SpeedControllerSeries::SpeedControllerSeries() {
	speedControllerList = new vector<SpeedController*>();
}


void SpeedControllerSeries::Set(float value) {
	for (int i = 0; i < (int)speedControllerList->size(); i++) {
		speedControllerList->at(i)->Set(value);
	}
}

void SpeedControllerSeries::Off() {
	Set(0.0f);
}

SpeedController* SpeedControllerSeries::Get(int index) {
	return speedControllerList->at(index);
}
