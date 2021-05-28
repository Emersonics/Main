#include "RectPrismRb.h"
#include "../MyVector.h"

void RectPrismRb::initializeRb(int particleType)
{
	this->particleType = particleType;

	MyVector ul = MyVector(-w / 2, h / 2);
	MyVector ll = MyVector(-w / 2, -h / 2);
	MyVector ur = MyVector(w / 2, h / 2);
	MyVector lr = MyVector(w / 2, -h / 2);

	points[0] = Utils::RotatePoint(ul, rotation) + position;
	points[1] = Utils::RotatePoint(ur, rotation) + position;
	points[2] = Utils::RotatePoint(lr, rotation) + position;
	points[3] = Utils::RotatePoint(ll, rotation) + position;
}
