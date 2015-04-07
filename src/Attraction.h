#pragma once
#include "PairForce.h"
#include "ofMain.h"

class Attraction :
	public PairForce
{
public:
	Attraction(ofPtr<Particle> P0, 
		ofPtr<Particle> P1,
		float G = 1.0f,
		float DistDevider = 0.3f*ofGetWidth(),
		float DistMin=1.0f);
	~Attraction(void);

	virtual void applyForce();
	virtual void draw();

private:
	ofParameterGroup parameters;
	ofParameter<float> _G;
	ofParameter<float> _DistDevider;
	ofParameter<float> _DistMin;


};

