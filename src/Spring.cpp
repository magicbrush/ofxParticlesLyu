#include "Spring.h"
#include "Particle.h"

Spring::Spring( 
	ofPtr<Particle> P0, 
	ofPtr<Particle> P1, 
	float Ks /*= 1.0f*/, 
	float Length_Rest/*=0.0f*/ ):
PairForce(P0,P1),ks(Ks),length_rest(Length_Rest)
{
	if(Length_Rest==0)
	{
		length_rest = 
			(getP0()->getPosition()-getP1()->getPosition()).length();
	}
}

Spring::~Spring( void )
{

}

void Spring::applyForce()
{
	ofVec3f p0top1 = getP0()->getPosition()-getP1()->getPosition();
	ofVec3f p1top0 = getP1()->getPosition()-getP0()->getPosition();
	ofVec3f p0top1Normalized = p0top1.getNormalized();
	ofVec3f p1top0Normalized = p1top0.getNormalized();

	float length_current = p0top1.length();
	float DeltaLength = length_current - length_rest;
	DeltaLength = ofClamp(DeltaLength,-10.0f,10.0);
	float absForce = ks*DeltaLength;

	ofVec3f ForceP0 = absForce * p0top1Normalized;
	ofVec3f ForceP1 = absForce * p1top0Normalized;

	getP0()->applyForce(ForceP0);
	getP1()->applyForce(ForceP1);
}

void Spring::draw()
{
	ofPoint Pos0 = getP0()->getPosition();
	ofPoint Pos1 = getP1()->getPosition();

	ofPushStyle();
	ofSetColor(0,0,0,15);
	ofSetLineWidth(ks);
	ofLine(Pos0,Pos1);
	ofPopStyle();
}
