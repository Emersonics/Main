#include "CableSpring.h"

void CableSpring::UpdateForce(MyParticle* particle, float time)
{
	MyVector pos = particle->position;

	MyVector force = pos - anchorPoint;

	float mag = force.getMagnitude();

	if (mag <= cableLength)
	{
		std::cout << mag << std::endl;
		particle->AddForce(MyVector(0, 0));
	}
	else
	{
		float springForce = -springConstant * abs(mag - cableLength);

		force.Normalize();
		force = force * springForce;


		particle->AddForce(force);
	}
}
