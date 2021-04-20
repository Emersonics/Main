#include "MyParticle.h"

MyParticle::MyParticle(float mass, MyVector position, MyVector velocity, MyVector acceleration):
	mass(mass), position(position), velocity(velocity), acceleration(acceleration)
{
	minVelocity = this->velocity.x;
}
void MyParticle::Update(float time)
{
	updatePosition(time);
	updateVelocity(time);
}

void MyParticle::updateVelocity(float time)
{
	velocity = velocity + acceleration * time;
}

void MyParticle::updatePosition(float time)
{
	position = position + (velocity * time) + ((acceleration * powf(time, 2)) * (1 / 2));
}

MyVector MyParticle::GetRenderPoint()
{
	return Utils::P6ToSFMLPoint(position);
}
