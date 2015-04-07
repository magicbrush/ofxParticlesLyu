#include "Particle.h"


Particle::Particle(
	ofPoint Pos /*= ofPoint(0,0,0)*/, 
	float Density /*= 1.0*/, 
	float Radius /*= 8.0f*/,
	ofFloatColor C /*= ofFloatColor::white*/, 
	float Q /*= 0.0f*/, 
	ofVec3f Vel /*= ofVec3f(0,0,0)*/, 
	ofVec3f Acc /*= ofVec3f(0,0,0)*/ ):
position(Pos),
velocity(Vel),
acceleration(Acc),
Force(ofVec3f(0)),
density(Density),
radius(Radius),
color(C),
q(Q)
{}

Particle::~Particle(void)
{

}

void Particle::update()
{
	computeAcceleration();

	float DeltaTime = ofGetLastFrameTime();
	accelerate(DeltaTime);
	move(DeltaTime);

	bounceInWindow();
}

void Particle::draw()
{
	ofFloatColor MyColor(color);
	float brightness = 1.0-pow(density,0.7);
	MyColor.setBrightness(brightness);
	ofPushStyle();
	ofFill();
	ofSetColor(MyColor);
	ofCircle(position,radius);
	ofNoFill();

	ofSetLineWidth(0.5f*abs(q)+0.5f);
	if(q<0)
	{
		ofSetColor(ofColor::black);
	}
	else
	{
		ofSetColor(ofColor::white);
	}	
	ofCircle(position,radius);
	ofSetColor(ofColor::black);
	ofDrawArrow(position,position+0.1f*velocity,5.0f);
	ofPopStyle();
}

void Particle::bounceInWindow()
{
	if(position.x>ofGetWidth()||position.x<0.0f)
	{
		velocity.x = -velocity.x;
	}
	if(position.y>ofGetHeight()||position.y<0.0f)
	{
		velocity.y = -velocity.y;
	}

	position.x = ofClamp(position.x, 0, ofGetWidth());
	position.y = ofClamp(position.y, 0, ofGetHeight());
}

void Particle::move( float DeltaTime )
{
	ofVec3f DeltaPostion = DeltaTime * velocity;
	position += DeltaPostion;
}

void Particle::accelerate( float DeltaTime )
{
	ofVec3f DeltaVelocity = DeltaTime * acceleration;
	velocity += DeltaVelocity;
	velocity.limit(5000.0);
}

void Particle::computeAcceleration()
{
	
	acceleration =  Force/getMass();
	Force = ofVec3f(0,0,0);
}

void Particle::applyForce( ofVec3f F )
{
	Force += F;
	Force.limit(10000.0f);
}

float Particle::getMass() const
{
	float Area = radius*radius*PI;
	float Mass = Area*density;

	return Mass;
}

float Particle::getRadius() const
{
	return radius;
}


