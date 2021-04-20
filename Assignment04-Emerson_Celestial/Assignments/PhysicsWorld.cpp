#include "PhysicsWorld.h"


void PhysicsWorld:: addParticle(MyParticle* particle)
{
	Particles.push_back(particle);
}

void PhysicsWorld::Update(float time)
{
	for (std::list<MyParticle*>::iterator i = Particles.begin();
		i != Particles.end(); i++)
	{
		(*i)->acceleration = gravity;
		(*i)->Update(time);
	}
}

void PhysicsWorld::UpdateParticeList()
{
	Particles.remove_if([](MyParticle* p) {return p->IsDestroyed(); });
}