#include "VerticalForce.h"
#include "Particle.h"

VerticalForce::VerticalForce( 
	ofPtr<Particle> P0,
	ofPtr<Particle> P1,
	float DistDevider,
	float DistMin
	):
PairForce(P0,P1)
{	
	parameters.setName("VerticalForce");	
	parameters.add(
		_DistDevider.set(
		"DistFactor",DistDevider,1.0f,10000.0f));
	parameters.add(
		_DistMin.set("DistMin",DistMin,0.01f,10.0f));
}

VerticalForce::~VerticalForce(void)
{
}

void VerticalForce::applyForce()
{
	ofPtr<Particle> P0 = getP0();
	ofPtr<Particle> P1 = getP1();

	float m0,m1;
	m0 = P0->getMass();
	m1 = P1->getMass();

	ofVec3f pos0,pos1;
	pos0 = P0->getPosition();
	pos1 = P1->getPosition();

	ofVec3f vel0,vel1;
	vel0 = P0->getVelocity();
	vel1 = P1->getVelocity();
	
	float dist = 
		ofClamp(pos0.distance(pos1),_DistMin,99999999.0f)
		/_DistDevider;

	ofVec3f p0top1 = pos1-pos0;
	ofVec3f p1top0 = pos0-pos1;
	ofVec3f p0top1n = p0top1.getNormalized();
	ofVec3f p1top0n = p1top0.getNormalized();

	ofVec3f F_1to0;
	ofVec3f Vel1Vertical = 
		vel1.rotated(90,ofVec3f(0,0,1));
	ofVec3f ForceDir10 = 
		(Vel1Vertical-vel0).normalized();
	F_1to0 = m1*ForceDir10/dist;
	P0->applyForce(0.001f*F_1to0);

	ofVec3f F_0to1;
	ofVec3f Vel0Vertical = 
		vel0.rotated(90,ofVec3f(0,0,1));
	ofVec3f ForceDir01 = 
		(Vel0Vertical-vel1).normalized();
	F_0to1 = m0*ForceDir01/dist;
	P1->applyForce(0.001f*F_0to1);
	
}

void VerticalForce::draw()
{
	
}
