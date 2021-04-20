#ifndef PHYSICSWORLD
#define PHYSICSWORLD
#include <list>
#include "MyParticle.h"


class PhysicsWorld
{
public:
	std::list<MyParticle*> Particles;
	void addParticle(MyParticle* particle);
	void Update(float time);
protected:
	void UpdateParticeList();
public:
	MyVector gravity = MyVector(0, 20.0f);
};

#endif // !PHYSICSWORLD

