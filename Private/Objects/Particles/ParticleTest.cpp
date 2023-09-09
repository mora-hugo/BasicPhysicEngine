#include "../../../Public/Objects/Particles/ParticleTest.h"

#include "of3dGraphics.h"
#include "ofGraphics.h"
ParticleTest::ParticleTest(const Vector3D& BasePosition, const Vector3D &BaseVelocity, const double &Size, const double& Duration) : Particle(BasePosition,BaseVelocity,Size,Duration)
{
    
}
void ParticleTest::Draw()
{
    ofSetColor(ofColor::blue);
    Particle::Draw();
    
}

void ParticleTest::Update()
{
    Position = Position + Velocity;

    //Simulate physics
    Velocity = Velocity.Add(Vector3D(0,1.0/100.0,0));
    Particle::Update();
}

