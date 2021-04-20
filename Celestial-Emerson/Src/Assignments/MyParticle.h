#ifndef MYPARTICLE
#define MYPARTICLE
#include "MyVector.h"
#include "Utils.h"
#include <math.h>
#include <iostream>

class MyParticle
{
public:
	MyParticle(float mass, MyVector position, MyVector velocity, MyVector acceleration);
public:
	float mass;
	float timeFinished;
	MyVector position;
	MyVector velocity;
	MyVector acceleration;
	float maxVelocity = 0;
	float minVelocity = 0;
protected:
	void updatePosition(float time);
	void updateVelocity(float time);
public:
	void Update(float time);
	MyVector GetRenderPoint();
};

#endif //MYPARTICLE


