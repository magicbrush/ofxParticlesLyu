#include "Alignment.h"
#include "Particle.h"

Alignment::Alignment( 
	ofPtr<Particle> P0,
	ofPtr<Particle> P1,
	float Strength /*= 1.0f*/, 
	float DistDevider, 
	float DistMin/*=1.0f*/ ):
PairForce(P0,P1)
{	
	parameters.setName("Alignment");
	parameters.add(
		_Strength.set("Strength",Strength,0.01f,10.0f));
	parameters.add(
		_DistDevider.set(
		"DistFactor",DistDevider,1.0f,10000.0f));
	parameters.add(
		_DistMin.set("DistMin",DistMin,0.01f,10.0f));

}

Alignment::~Alignment(void)
{
}

void Alignment::applyForce()
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
	float distSquare = dist*dist;

	//ofVec3f p0top1 = pos1-pos0;
	//ofVec3f p1top0 = pos0-pos1;
	//ofVec3f p0top1n = p0top1.getNormalized();
	//ofVec3f p1top0n = p1top0.getNormalized();

	ofVec3f F_0to1 = 0.1f*m1*_Strength*(vel1-vel0)/distSquare ;
	ofVec3f F_1to0 = 0.1f*m0*_Strength*(vel0-vel1)/distSquare ;

	P0->applyForce(F_0to1);
	P1->applyForce(F_1to0);
}

void Alignment::draw()
{
	
}
