#include "CollisionMinDist.h"
#include "Particle.h"

CollisionMinDist::CollisionMinDist( 
	ofPtr<Particle> P0,
	ofPtr<Particle> P1,
	float minDist/*=20.0f*/ ):
Collision(P0,P1)
{
	_MinDist.set("MinDistance",minDist,0.0f,256.0f);

}

CollisionMinDist::~CollisionMinDist(void)
{

}

void CollisionMinDist::collide()
{
	ofPtr<Particle> P0 = getP0();
	ofPtr<Particle> P1 = getP1();

	ofVec3f pos0 = P0->getPosition();
	ofVec3f pos1 = P1->getPosition();

	float dist = pos0.distance(pos1);
	if(dist<_MinDist)
	{
		ofVec3f dir01 = (pos1-pos0).normalize();
		ofVec3f dir10 = (pos0-pos1).normalize();

		float shiftDist = (_MinDist-dist)/2.0f;

		ofVec3f pos0s(pos0),pos1s(pos1);
		pos0s += dir10*shiftDist;
		pos1s += dir01*shiftDist;
		P0->setPosition(pos0s);
		P1->setPosition(pos1s);
	}


}

