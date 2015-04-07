#include "Resistance.h"
#include "Particle.h"


Resistance::Resistance( 
	ofPtr<Particle> P,
	float resistance):
	SingleForce(P)	
{
	_Resistance.set("Resistance",resistance,0.0f,10.0f);
}

Resistance::~Resistance(void)
{

}

void Resistance::applyForce()
{
	ofPtr<Particle> P = getP();

	ofVec3f Vel = P->getVelocity();
	float M = P->getMass();

	ofVec3f ForceResist = - Vel * _Resistance * M;
	P->applyForce(ForceResist);
}

void Resistance::draw()
{

}
