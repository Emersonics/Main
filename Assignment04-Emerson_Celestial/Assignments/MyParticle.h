#ifndef MYPARTICLE
#define MYPARTICLE
#include "MyVector.h"
#include "Utils.h"
#include <math.h>
#include <iostream>

class MyParticle
{
public: //consrtuctor
	MyParticle(float mass, MyVector position, MyVector velocity, MyVector acceleration);
public:
	float mass;
	float timeFinished;
	MyVector position;
	MyVector velocity;
	MyVector acceleration;
	float maxXVelocity = 0;
	float minXVelocity = 0;
	float maxYVelocity = 0;
	float minYVelocity = 0;
protected:
	void updatePosition(float time);
	void updateVelocity(float time);
	bool isDestroyed = false;
public:
	void Update(float time);
	MyVector GetRenderPoint();
	bool IsDestroyed() {
		return isDestroyed;
	}
	void Destroy();
public:
	float dampening = 0.9;
	void AddForce(MyVector v);
	void ResetForce();
protected:
	MyVector accumulatedForce = MyVector();
};

#endif //MYPARTICLE


