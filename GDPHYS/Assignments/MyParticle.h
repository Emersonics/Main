#ifndef MYPARTICLE
#define MYPARTICLE
#include "MyVector.h"
#include "Utils.h"
#include <math.h>
#include <iostream>

class MyParticle
{
public: //consrtuctor
	MyParticle(float mass, MyVector position, MyVector velocity, MyVector acceleration, float lifeSpan);
	MyParticle();
public:
	float mass;
	float lifeSpan;
	MyVector position;
	MyVector velocity;
	MyVector acceleration;
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
	void checkLifeSpan(float time);
public:
	float dampening = 0.8;
	void AddForce(MyVector v);
	void ResetForce();
protected:
	MyVector accumulatedForce = MyVector();
public:
	float radius = 10;
	//elasticity/restitution 1-being so elastic and 0 - no elasticity(bounciness)
	float restitution = 1;
};

#endif //MYPARTICLE


