#include "ofApp.h"
#include "Particle.h"
#include "Collision.h"
#include "CollisionMinDist.h"
#include "SingleForce.h"
#include "Resistance.h"
#include "RandPropulsion.h"
#include "PairForce.h"
#include "Spring.h"
#include "Attraction.h"
#include "Alignment.h"
#include "VerticalForce.h"


//--------------------------------------------------------------
void ofApp::setup(){

	for(int i=0;i<20;i++)
	{
		ofPtr<Particle> P;
		ofPoint Pos(
			ofRandom(0,ofGetWidth()),
			ofRandom(0,ofGetHeight()),
			0);
		ofVec3f V;
		V.x = ofRandom(-10.0f,10.0f);
		V.y = ofRandom(-10.0f,10.0f);
		ofFloatColor RandColor(
			ofRandom(0,1),
			ofRandom(0,1),
			ofRandom(0,1),
			1.0f);
		P.reset(new Particle(
			Pos,
			ofRandom(0.1f,1.0f),
			ofRandom(5.0f,10.0f),
			RandColor,
			ofRandom(-5.0f,5.0f),
			V));
		Pts.push_back(P);
	}

	//setupCollision();

	//setupResistanceForces();
	//setupRandPropulsions();

	setupSprings();
	//setupAttractions();
	setupVerticalForces();
	//setupAlignments();
}

//--------------------------------------------------------------
void ofApp::update(){
	
	updateParticles();
	update_collision();
	update_singleForce();
	update_pairForce();

}

//--------------------------------------------------------------
void ofApp::draw(){

	vector<ofPtr<Particle> >::iterator itr;
	for(itr = Pts.begin();itr<Pts.end();itr++)
	{
		ofPtr<Particle> pt = *itr;
		pt->draw();
	}

	vector<ofPtr<SingleForce> >::iterator itSF;
	for(itSF=SF.begin();itSF<SF.end();itSF++)
	{
		ofPtr<SingleForce> SF = *itSF;
		SF->draw();
	}

	vector<ofPtr<PairForce> >::iterator ifPF;
	for(ifPF=PF.begin();ifPF<PF.end();ifPF++)
	{
		ofPtr<PairForce> PF = *ifPF;
		PF->draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::setupSprings()
{
	int NumPts = Pts.size();
	for(int i=0;i<20;i++)
	{
		int id0 = floor(ofRandom(0,NumPts-1));
		int id1 = floor(ofRandom(0,NumPts-1));
		if(id0==id1)
		{
			continue;
		}
		ofPtr<Spring> sp;
		ofPtr<Particle> p0,p1;
		p0 = Pts[id0];
		p1 = Pts[id1];
		sp.reset(
			new Spring(p0,p1,
			ofRandom(0.5f,5.0f)));
		Sps.push_back(sp);
		PF.push_back(sp);
	}
}

void ofApp::setupAttractions()
{
	int NumPts = Pts.size();
	for(int i=0;i<NumPts;i++)
	{
		for(int j=i;j<NumPts;j++)
		{
			ofPtr<Attraction> att;
			ofPtr<Particle> p0,p1;
			p0 = Pts[i];
			p1 = Pts[j];

			att.reset(new Attraction(p0,p1));
			Ats.push_back(att);
			PF.push_back(att);
		}
	}
}

void ofApp::setupAlignments()
{
	int NumPts = Pts.size();
	for(int i=0;i<NumPts;i++)
	{
		for(int j=i;j<NumPts;j++)
		{
			ofPtr<Alignment> al;
			ofPtr<Particle> p0,p1;
			p0 = Pts[i];
			p1 = Pts[j];
			if(p0==p1)
			{
				continue;
			}

			al.reset(new Alignment(p0,p1));
			Als.push_back(al);
			PF.push_back(al);
		}
	}
}

void ofApp::setupResistanceForces()
{
	int NumPts = Pts.size();
	for(int i=0;i<NumPts;i++)
	{
		ofPtr<Resistance> resistForce;
		ofPtr<Particle> Pt;
		Pt = Pts[i];
		resistForce.reset(new Resistance(Pt,0.1f));
		Rfs.push_back(resistForce);
		SF.push_back(resistForce);
	}
}

void ofApp::setupCollision()
{
	int NumPts = Pts.size();
	for(int i=0;i<NumPts;i++)
	{
		for(int j=i;j<NumPts;j++)
		{
			ofPtr<CollisionMinDist> c;
			ofPtr<Particle> p0,p1;
			p0 = Pts[i];
			p1 = Pts[j];
			if(p0==p1)
			{
				continue;
			}
			float r0,r1;
			r0 = p0->getRadius();
			r1 = p1->getRadius();
			c.reset(new CollisionMinDist(p0,p1,r0+r1));
			Cmd.push_back(c);
			CL.push_back(c);
		}
	}
}

void ofApp::updateParticles()
{
	vector<ofPtr<Particle> >::iterator itr;
	for(itr = Pts.begin();itr<Pts.end();itr++)
	{
		ofPtr<Particle> pt = *itr;				
		pt->update();
	}
}

void ofApp::update_collision()
{
	vector<ofPtr<Collision> >::iterator itCL;
	for(itCL=CL.begin();itCL<CL.end();itCL++)
	{
		ofPtr<Collision> C = *itCL;
		C->collide();
	}
}

void ofApp::update_singleForce()
{
	vector<ofPtr<SingleForce> >::iterator itSF;
	for(itSF=SF.begin();itSF<SF.end();itSF++)
	{
		ofPtr<SingleForce> SF = *itSF;
		SF->applyForce();
	}
}

void ofApp::update_pairForce()
{
	vector<ofPtr<PairForce> >::iterator ifPF;
	for(ifPF=PF.begin();ifPF<PF.end();ifPF++)
	{
		ofPtr<PairForce> PF = *ifPF;
		PF->applyForce();
	}
}

void ofApp::setupRandPropulsions()
{
	int NumPts = Pts.size();
	for(int i=0;i<NumPts;i++)
	{
		ofPtr<RandPropulsion> resistForce;
		ofPtr<Particle> Pt;
		Pt = Pts[i];
		resistForce.reset(new RandPropulsion(Pt,0.1f));
		Rps.push_back(resistForce);
		SF.push_back(resistForce);
	}
}

void ofApp::setupVerticalForces()
{
	int NumPts = Pts.size();
	for(int i=0;i<NumPts;i++)
	{
		for(int j=i;j<NumPts;j++)
		{
			ofPtr<VerticalForce> att;
			ofPtr<Particle> p0,p1;
			p0 = Pts[i];
			p1 = Pts[j];

			att.reset(new VerticalForce(p0,p1));
			Vfs.push_back(att);
			PF.push_back(att);
		}
	}
}
