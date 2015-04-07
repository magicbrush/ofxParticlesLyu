#include "RandPropulsion.h"
#include "Particle.h"


RandPropulsion::RandPropulsion( 
	ofPtr<Particle> P,
	float RandPropulsion):
	SingleForce(P)	
{
	_RandPropulsion.set("RandPropulsion",RandPropulsion,0.0f,10.0f);
}

RandPropulsion::~RandPropulsion(void)
{

}

void RandPropulsion::applyForce()
{
	ofPtr<Particle> P = getP();

	ofFloatColor C = P->getColor();
	float sat = 10000.0f*C.getSaturation();
	
	float timeNow = ofGetElapsedTimef();
	ofVec3f RForce(
		sat*ofSignedNoise(1.12345*timeNow),
		sat*ofSignedNoise(0.92343f*timeNow),
		0);
	
	P->applyForce(RForce);
}

void RandPropulsion::draw()
{

}
