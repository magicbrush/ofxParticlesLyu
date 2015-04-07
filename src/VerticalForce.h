#pragma once
#include "PairForce.h"
#include "ofMain.h"

class VerticalForce :
	public PairForce
{
public:
	VerticalForce(ofPtr<Particle> P0, 
		ofPtr<Particle> P1,
		float DistDevider = 0.3f*ofGetWidth(),
		float DistMin=1.0f);
	~VerticalForce(void);

	virtual void applyForce();
	virtual void draw();

private:
	ofParameterGroup parameters;	
	ofParameter<float> _DistDevider;
	ofParameter<float> _DistMin;

};

