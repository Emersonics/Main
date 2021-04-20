#include "MyVector.h"

MyVector::MyVector(float x, float y, float z) : x(x), y(y), z(z)
{
	this->y = -1 * y;
}

//gets the direction
void MyVector::Normalize()
{
	float n = getMagnitude();
	if (n > 0) {
		(*this) = (*this) * ((1.0f) / n);
	}
}

float MyVector::getMagnitude()
{
	float magnitude;
	magnitude = sqrt(pow(this->x, 2) + pow(this->y, 2));
	return magnitude;
}

MyVector MyVector::getDirection(float magnitude)
{
	MyVector direction(this->x, this->y, 0);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	return direction;
}

MyVector MyVector::operator+(MyVector vec)
{
	MyVector newVector(this->x + vec.x, this->y + vec.y);
	return newVector;
}

MyVector MyVector::operator-(MyVector vec)
{
	MyVector newVector(this->x - vec.x, this->y - vec.y);
	return newVector;
}

MyVector MyVector::operator*(const float scalar)
{
	MyVector newVector(this->x * scalar, this->y * scalar);
	return newVector;
}

void MyVector::operator+=(MyVector vec)
{
	MyVector newVector(this->x + vec.x, this->y + vec.y);
}

void MyVector::operator-=(MyVector vec)
{
	MyVector newVector(this->x - vec.x, this->y - vec.y);
}

void MyVector::operator*=(const float scalar)
{
	MyVector newVector(this->x * scalar, this->y * scalar);
}

MyVector MyVector::getComponentProduct(MyVector vec1, MyVector vec2)
{
	MyVector newVector(vec1.x * vec2.x, vec1.y * vec2.y);
	return newVector;
}

float MyVector::getScalarProduct(MyVector vec1, MyVector vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

MyVector MyVector::getVectorProduct(MyVector vec1, MyVector vec2)
{
	MyVector newVector((vec1.y * vec2.z) - (vec1.z * vec2.y),
		(vec1.z * vec2.x) - (vec1.x * vec2.z),
		(vec1.x * vec2.y) - (vec1.y * vec2.x));
	return newVector;
}

float MyVector::operator*(MyVector v)
{
	return this->x * v.x + this->y * v.y;
}