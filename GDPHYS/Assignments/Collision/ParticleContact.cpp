#include "ParticleContact.h"
void ParticleContact::Resolve(float time)
{
	ResolveVelocity(time);
}

float ParticleContact::GetSeparatingSpeed()
{
	MyVector velocityDiff = particles[0]->velocity;
	if (particles[1]) velocityDiff -= particles[1]->velocity;
	return velocityDiff * collisionNormal;
}

void ParticleContact::ResolveVelocity(float time)
{
	float Ss = GetSeparatingSpeed();
	if (Ss > 0)
	{
		return;
	}

	//separating speed after collision
	float Sf = -restitution * Ss;
	float deltaSpeed = Sf - Ss;

	//total Momentum
	float totalMass = (float)1 / particles[0]->mass;
	if (particles[1]) totalMass += (float)1 / particles[1]->mass;

	if (totalMass <= 0) return;

	//	i	=	dV	*	m; //divide since the mass is 1/m
	float impulse_mag = deltaSpeed / totalMass;
	MyVector Impulse = collisionNormal * impulse_mag;

	//	I / m
	MyVector V_0 = Impulse * ((float)1 / particles[0]->mass);
	//			Vf = Vi + I/m
	particles[0]->velocity = particles[0]->velocity + V_0;

	if (particles[1])
	{
		MyVector V_1 = Impulse * (-(float)1 / particles[0]->mass);
		particles[1]->velocity = particles[1]->velocity + V_1;
	}
}