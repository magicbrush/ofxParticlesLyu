#pragma once

#include "ofMain.h"

class Particle;

class Collision;
class CollisionMinDist;

class SingleForce;
class Resistance;
class RandPropulsion;

class PairForce;
class Spring;
class Attraction;
class Alignment;
class VerticalForce;


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void setupCollision();
		void setupResistanceForces();
		void setupAlignments();
		void setupAttractions();
		void setupSprings();
		void setupVerticalForces();

		void update_pairForce();
		void update_singleForce();
		void update_collision();
		void updateParticles();
		void setupRandPropulsions();

		
		// Particles
		vector<ofPtr<Particle> > Pts;

		// Collisions
		vector<ofPtr<Collision> > CL; 
		vector<ofPtr<CollisionMinDist> > Cmd;
		
		// Single Forces
		vector<ofPtr<SingleForce> > SF;		
		vector<ofPtr<Resistance> > Rfs;
		vector<ofPtr<RandPropulsion> > Rps;

		// Pair Forces
		vector<ofPtr<PairForce> > PF;
		vector<ofPtr<Spring> > Sps;
		vector<ofPtr<Attraction> > Ats;
		vector<ofPtr<Alignment> > Als;
		vector<ofPtr<VerticalForce> > Vfs;
};
