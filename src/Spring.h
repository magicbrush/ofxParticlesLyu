#pragma once

#include "ofMain.h"
#include "PairForce.h"
class Particle;

class Spring:
	public PairForce
{
public:
	Spring(
		ofPtr<Particle> P0, 
		ofPtr<Particle> P1,
		float Ks = 1.0f,
		float Length_Rest=0.0f);
	
	~Spring(void);

	void applyForce();
	void draw();

private:
	ofPtr<Particle> p0,p1;
	float ks;
	float length_rest;


};

