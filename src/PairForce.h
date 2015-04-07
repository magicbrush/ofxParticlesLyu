#pragma once
#include "ofMain.h"
class Particle;

class PairForce
{
public:
	PairForce(
		ofPtr<Particle> P0, 
		ofPtr<Particle> P1);
	virtual ~PairForce(void);

	virtual void applyForce()=0;
	virtual void draw()=0;

protected:
	ofPtr<Particle> getP0();
	ofPtr<Particle> getP1();

private:
	ofPtr<Particle> p0,p1;

};

