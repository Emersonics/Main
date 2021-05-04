#ifndef FORCEGENERATOR
#define FORCEGENERATOR
#include  "MyParticle.h";

class ForceGenerator
{
public:
	virtual void UpdateForce(MyParticle* p, float time)
	{
		//base definition
		p->AddForce(MyVector(0,0));
	}
};

#endif //FORCEGENERATOR

