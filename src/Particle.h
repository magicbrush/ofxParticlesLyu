#pragma once

#include "ofMain.h"

class Particle
{
public:	
	Particle(
		ofPoint Pos = ofPoint(0,0,0),
		float Density = 1.0,
		float Radius = 8.0f,
		ofFloatColor C = ofFloatColor::white,
		float Q = 0.0f,
		ofVec3f Vel = ofVec3f(0,0,0),
		ofVec3f Acc = ofVec3f(0,0,0));
	virtual ~Particle(void);

	ofPoint getPosition() const { return position; }
	void setPosition(ofPoint val) { position = val; }
	ofVec3f getVelocity() const { return velocity; }	
	float getMass() const;
	float getRadius() const;
	ofFloatColor getColor() const { return color; }
	void setColor(ofFloatColor val) { color = val; }
	float getQ() const { return q; }
	void setQ(float val) { q = val; }

	virtual void update();	
	virtual void draw();	

	void applyForce(ofVec3f F);

private:	
	void accelerate( float DeltaTime );
	void move( float DeltaTime );
	void bounceInWindow();
	void computeAcceleration();
	

private:
	// properties:
	ofPoint position;	
	ofVec3f velocity;	
	ofVec3f acceleration;	
	ofVec3f Force;
		
	float  density;
	float  radius; 
	ofFloatColor color;	
	float q;
	




};

