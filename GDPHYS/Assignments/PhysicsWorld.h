#ifndef PHYSICSWORLD
#define PHYSICSWORLD
#include <list>
#include "MyParticle.h"
#include "ForceRegistry.h"
#include "GravityForceGenerator.h"

class PhysicsWorld
{
public:
	std::list<MyParticle*> Particles;
	void addParticle(MyParticle* particle);
	void Update(float time);
protected:
	void UpdateParticeList();
public:
	MyVector gravity = MyVector(0, 0); //this is downward
public:
	PhysicsWorld();
public:
	ForceRegistry foreceRegistry;
protected:
	GravityForceGenerator Gravity = GravityForceGenerator(MyVector(0, -9.8));
};

#endif // !PHYSICSWORLD

