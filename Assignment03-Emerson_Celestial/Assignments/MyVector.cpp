#include "MyVector.h"

sample::MyVector:: MyVector(float x, float y, float z) : x(x), y(y), z(z)
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
	MyVector direction(this->x,this->y, 0);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	return direction;
}

sample::MyVector sample::MyVector::operator+(sample::MyVector& vec)
{
	MyVector newVector(this->x + vec.x, this->x + vec.y, 0);
	return newVector;
}

sample::MyVector sample::MyVector::operator-(sample::MyVector& vec)
{
	MyVector newVector(this->x - vec.x, this->x - vec.y, 0);
	return newVector;
}

sample::MyVector sample::MyVector::operator*(const float scalar)
{
	MyVector newVector(this->x * scalar, this->x * scalar, 0);
	return newVector;
}

sample::MyVector sample::MyVector::getComponentProduct(sample::MyVector& vec1, sample::MyVector& vec2)
{
	MyVector newVector(vec1.x * vec2.x, vec1.y * vec2.y, 0);
	return newVector;
}

float sample::MyVector::getScalarProduct(sample::MyVector& vec1, sample::MyVector& vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

sample::MyVector sample::MyVector::getVectorProduct(sample::MyVector& vec1, sample::MyVector& vec2)
{
	MyVector newVector((vec1.y * vec2.z) - (vec1.z * vec2.y),
					   (vec1.z * vec2.x) - (vec1.x * vec2.z),
					   (vec1.x * vec2.y) - (vec1.y * vec2.x));
	return newVector;
}