#include "ParticleLink.h"

float ParticleLink::GetDistance()
{
	MyVector dist = particles[0]->position - particles[1]->position;
	return dist.getMagnitude();
}
