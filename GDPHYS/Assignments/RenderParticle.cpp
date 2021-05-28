#include "RenderParticle.h"

void RenderParticle::Draw(sf::RenderWindow* window)
{
	cout << "Hello World" << endl;
	if (!PhysicParticle->IsDestroyed())
	{
		MyVector v = PhysicParticle->GetRenderPoint();
		MyVector c = CircParticle->GetRenderPoint();
		MyVector r = RectParticle->GetRenderPoint();
		switch (particleType)
		{
		case 0:
			ParticleShape->setPosition(v.x, v.y);
			break;
		case 2:
			circleShape->setPosition(c.x, c.y);
			break;
		case 3:
			rectShape->setPosition(r.x, r.y);
			break;
		}

		/*MyVector v = PhysicParticle->GetRenderPoint();
		ParticleShape->setPosition(v.x, v.y);*/

		//draw the shape
		//0 = Particle 1 = Rigid 2 = Circ 3 = Rect
		switch (particleType)
		{
		case 0:
			window->draw(*ParticleShape);
			break;
		case 2:
			window->draw(*circleShape);
			break;
		case 3:
			window->draw(*rectShape);
			break;
		}
	}
}


RenderParticle::RenderParticle(MyParticle* p, sf::Shape* s) : PhysicParticle(p), ParticleShape(s)
{
	this->particleType = p->particleType;
}

RenderParticle::RenderParticle(RectPrismRb* p, sf::RectangleShape* s) : RectParticle(p), rectShape(s)
{
	this->particleType = p->particleType;
}
RenderParticle::RenderParticle(CircleRb* p, sf::CircleShape* s) : CircParticle(p), circleShape(s)
{
	this->particleType = p->particleType;
}
