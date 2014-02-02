#include "Invertable.h"

Invertable::Invertable(bool isInverted) {
	this->isInverted = isInverted;
}

void Invertable::Invert() {
	isInverted = !isInverted;
}

bool Invertable::IsInverted() {
	return isInverted;
}
