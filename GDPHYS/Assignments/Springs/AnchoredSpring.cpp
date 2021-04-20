#include "AnchoredSpring.h"

void AnchoredSpring::UpdateForce(MyParticle* particle, float time)
{
	MyVector pos = particle->position;

	MyVector force = pos - anchorPoint;

	float mag = force.getMagnitude();
	
	float springForce = -springConstant * abs(mag - restLength);

	force.Normalize();
	force = force * springForce;

	particle->AddForce(force);
}