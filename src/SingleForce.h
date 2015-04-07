#pragma once
#include "ofMain.h"
class Particle;

class SingleForce
{
public:
	SingleForce(ofPtr<Particle> P);
	virtual ~SingleForce(void);

	virtual void applyForce()=0;
	virtual void draw()=0;

protected:
	ofPtr<Particle> getP();	

private:
	ofPtr<Particle> p;

};

