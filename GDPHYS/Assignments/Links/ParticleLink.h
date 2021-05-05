#pragma once
#include "../Collision//ParticleContact.h"
#include "../MyParticle.h"

class ParticleLink
{
public:
	//Particles that are linked
	MyParticle* particles[2];
	//Returns a contact if particles violate the condition for the link
	virtual ParticleContact* GetContact() { return nullptr; }

public:
	float GetDistance();
};

