#pragma once
#include "ofMain.h"
#include "SingleForce.h"
class Particle;

class RandPropulsion:
	public SingleForce
{
public:
	RandPropulsion(ofPtr<Particle> P, float RandPropulsion=0.8f);
	virtual ~RandPropulsion(void);

	virtual void applyForce();
	virtual void draw();

private:
	ofParameter<float> _RandPropulsion;


};

