#include "RectPrismRb.h"
#include "../MyVector.h"
#include "../Utils.h"

void RectPrismRb::initializeRb(int particleType)
{
	this->particleType = particleType;

	MyVector ul = MyVector(-w / 2, h / 2);
	MyVector ll = MyVector(-w / 2, -h / 2);
	MyVector ur = MyVector(w / 2, h / 2);
	MyVector lr = MyVector(w / 2, -h / 2);
	/*
	cout << "ul: " << ul.x << ":" << ul.y << endl;
	cout << "ll: " << ll.x << ":" << ll.y << endl;
	cout << "ur: " << ur.x << ":" << ur.y << endl;
	cout << "lr: " << lr.x  << ":"<< lr.y<< endl;*/
	points.resize(4);
	points[0] = Utils::RotatePoint(ul, rotation) + position;
	points[1] = Utils::RotatePoint(ur, rotation) + position;
	points[2] = Utils::RotatePoint(lr, rotation) + position;
	points[3] = Utils::RotatePoint(ll, rotation) + position;

	cout << "ul: " << points[0].x << ":" << points[0].y << endl;
	cout << "ll: " << points[1].x << ":" << points[1].y << endl;
	cout << "ur: " << points[2].x << ":" << points[2].y << endl;
	cout << "lr: " << points[3].x << ":" << points[3].y << endl;
}
