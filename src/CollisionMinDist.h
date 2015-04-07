#pragma once
#include "ofMain.h"
#include "Collision.h"
class Particle;

class CollisionMinDist:
	public Collision
{
public:
	CollisionMinDist(
		ofPtr<Particle> P0,
		ofPtr<Particle> P1,
		float minDist=20.0f);
	virtual ~CollisionMinDist(void);

	virtual void collide();	

private:
	ofParameter<float> _MinDist;


};

