#pragma once
#include "../MyParticle.h"

class ParticleContact
{
protected:
	float GetSeparatingSpeed();
	void ResolveVelocity(float time);

public:
	MyParticle* particles[2];
	float restitution;
	MyVector collisionNormal;

public:
	void Resolve(float time);
};

