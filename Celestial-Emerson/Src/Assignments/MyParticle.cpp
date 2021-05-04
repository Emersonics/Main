#include "MyParticle.h"

MyParticle::MyParticle(float mass, MyVector position, MyVector velocity, MyVector acceleration, float lifeSpan):
	mass(mass), position(position), velocity(velocity), acceleration(acceleration), lifeSpan(lifeSpan)
{
}MyParticle::MyParticle()
{
}
void MyParticle::Update(float time)
{
	updatePosition(time);
	updateVelocity(time);
	checkLifeSpan(time);
	ResetForce();
}

void MyParticle::checkLifeSpan(float time)
{
	lifeSpan -= time;
	if (lifeSpan <= 0.0f) {
		Destroy();
	}
}

void MyParticle::updateVelocity(float time)
{
	acceleration = acceleration + (accumulatedForce * (1 / mass));
	velocity = velocity + acceleration * time;
	velocity = velocity * powf(dampening, time);
}

void MyParticle::updatePosition(float time)
{
	//P2
	position = position + (velocity * time) + ((acceleration * powf(time, 2)) * (1 / 2));
}

MyVector MyParticle::GetRenderPoint()
{
	return Utils::P6ToSFMLPoint(position);
}

void MyParticle::Destroy()
{
	this->isDestroyed = true;
}


void MyParticle::AddForce(MyVector v)
{
	accumulatedForce = accumulatedForce + v;
}

void MyParticle::ResetForce()
{
	accumulatedForce = MyVector(0, 0);
	acceleration = MyVector(0, 0);
}
