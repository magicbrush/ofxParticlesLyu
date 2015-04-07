#include "SingleForce.h"



SingleForce::SingleForce( ofPtr<Particle> P ):
	p(P)
{

}

SingleForce::~SingleForce(void)
{

}

ofPtr<Particle> SingleForce::getP()
{
	return p;
}
