#ifndef PARTICLESPRING
#define PARTICLESPRING
#include "../MyParticle.h"
#include "../ForceGenerator.h"

class ParticleSpring : public ForceGenerator
{
private:
	MyParticle* otherParticle;
	float springConstant;
	float restLength;
public:
	ParticleSpring(MyParticle* _otherParticle, float _springConst, float _restLen) :
		otherParticle(_otherParticle), springConstant(_springConst), restLength(_restLen){}
	void UpdateForce(MyParticle* particle, float time)override;
};

#endif // !PARTICLESPRING

