#pragma once

#include "ofMain.h"
#include "Public/Enum/EProjectileType.h"
#include "Public\Objects\Particles\ParticleFireball.h"
#include "Public/Objects/Particles/ParticleBullet.h"
#include "Public/Objects/Particles/ParticleSystem.h"

class ParticleTest;

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		void SpawnParticle(const Vector3D & Position, const Vector3D & Velocity);
private:
	ParticleSystem<ParticleFireball> FireBalls;
	ParticleSystem<ParticleBullet> Bullets;

	EProjectileType CurrentParticleType = Bullet;
	
	Vector3D StartingVector;
	bool bDrawLine = false;
};
