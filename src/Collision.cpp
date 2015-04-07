#include "Collision.h"


Collision::Collision( ofPtr<Particle> P0,ofPtr<Particle> P1 ):
	p0(P0),p1(P1)
{

}

Collision::~Collision(void)
{

}

ofPtr<Particle> Collision::getP0()
{
	return p0;
}

ofPtr<Particle> Collision::getP1()
{
	return p1;
}
