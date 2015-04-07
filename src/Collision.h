#pragma once
#include "ofMain.h"
class Particle;

class Collision
{
public:
	Collision(ofPtr<Particle> P0,ofPtr<Particle> P1);
	virtual ~Collision(void);

	virtual void collide()=0;	

protected:
	ofPtr<Particle> getP0();
	ofPtr<Particle> getP1();

private:
	ofPtr<Particle> p0,p1;	

};

