#ifndef INVERTABLE_H
#define INVERTABLE_H
class Invertable {
public:
	
	Invertable(bool isInverted = false);
	virtual void Invert();
	virtual bool IsInverted();
private:
	bool isInverted;
};
#endif
