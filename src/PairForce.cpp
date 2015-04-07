#include "PairForce.h"



PairForce::PairForce( ofPtr<Particle> P0, ofPtr<Particle> P1 ):
	p0(P0),p1(P1)
{

}

PairForce::~PairForce(void)
{

}

ofPtr<Particle> PairForce::getP0()
{
	return p0;
}

ofPtr<Particle> PairForce::getP1()
{
	return p1;
}
