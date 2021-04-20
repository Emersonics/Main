#include "MyVector.h"
#include <iostream>
#include <math.h>

sample::MyVector:: MyVector(float x, float y): x(x), y(y)
{
	
}

float sample::MyVector::getMagnitude()
{
	float magnitude;
	magnitude = sqrt(pow(this->x,2) + pow(this->y,2));
	return magnitude;
}

sample::MyVector sample::MyVector::getDirection(float magnitude)
{
	MyVector direction(this->x,this->y);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	return direction;
}