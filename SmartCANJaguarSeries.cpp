#include "SmartCANJaguarSeries.h"
SmartCANJaguarSeries::SmartCANJaguarSeries() {}
void SmartCANJaguarSeries::Add(SmartCANJaguar* jaguar) {
	jagList.push_back(jaguar);
}

void SmartCANJaguarSeries::Set(float value) {
	for (int i = 0; i < (int)jagList.size(); i++) {
		jagList.at(i)->Set(value);
	}
}

void SmartCANJaguarSeries::Off() {
	Set(0.0f);
}

SmartCANJaguar* SmartCANJaguarSeries::Get(int index) {
	return jagList.at(index);
}
