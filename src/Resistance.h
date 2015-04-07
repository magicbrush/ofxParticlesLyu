#pragma once
#include "ofMain.h"
#include "SingleForce.h"
class Particle;

class Resistance:
	public SingleForce
{
public:
	Resistance(ofPtr<Particle> P, float resistance=0.8f);
	virtual ~Resistance(void);

	virtual void applyForce();
	virtual void draw();

private:
	ofParameter<float> _Resistance;


};

