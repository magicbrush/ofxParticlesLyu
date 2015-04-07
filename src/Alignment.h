#pragma once
#include "PairForce.h"
#include "ofMain.h"

class Alignment :
	public PairForce
{
public:
	Alignment(ofPtr<Particle> P0, 
		ofPtr<Particle> P1,
		float Strength = 1.0f,
		float DistDevider = 0.3f*ofGetWidth(),
		float DistMin=1.0f);
	~Alignment(void);

	virtual void applyForce();
	virtual void draw();

private:
	ofParameterGroup parameters;
	ofParameter<float> _Strength;
	ofParameter<float> _DistDevider;
	ofParameter<float> _DistMin;


};

