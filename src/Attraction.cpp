#include "Attraction.h"
#include "Particle.h"

Attraction::Attraction( 
	ofPtr<Particle> P0,
	ofPtr<Particle> P1,
	float G /*= 1.0f*/, 
	float DistDevider, 
	float DistMin/*=1.0f*/ ):
PairForce(P0,P1)
{	
	parameters.setName("Attraction");
	parameters.add(
		_G.set("G",G,0.01f,10.0f));
	parameters.add(
		_DistDevider.set(
		"DistFactor",DistDevider,1.0f,10000.0f));
	parameters.add(
		_DistMin.set("DistMin",DistMin,0.01f,10.0f));
}

Attraction::~Attraction(void)
{
}

void Attraction::applyForce()
{
	ofPtr<Particle> P0 = getP0();
	ofPtr<Particle> P1 = getP1();

	float m0,m1;
	m0 = P0->getMass();
	m1 = P1->getMass();

	ofVec3f pos0,pos1;
	pos0 = P0->getPosition();
	pos1 = P1->getPosition();
	float dist = 
		ofClamp(pos0.distance(pos1),_DistMin,99999999.0f)
		/_DistDevider;

	float force = _G*m0*m1/(dist*dist);

	ofVec3f p0top1 = pos1-pos0;
	ofVec3f p1top0 = pos0-pos1;

	ofVec3f p0top1n = p0top1.getNormalized();
	ofVec3f p1top0n = p1top0.getNormalized();

	ofVec3f F_0to1 = p0top1n * force;
	ofVec3f F_1to0 = p1top0n * force;

	P0->applyForce(F_0to1);
	P1->applyForce(F_1to0);
}

void Attraction::draw()
{
	
}
