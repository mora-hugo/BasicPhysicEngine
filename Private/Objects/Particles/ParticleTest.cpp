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
    Trails.Draw();
    
}

void ParticleTest::Update()
{
    Particle::Update();
    Trails.AddParticle(Position,Velocity.Negate().Multiply(ofRandomf()+1),Size-5,ofRandomf()+1*0.5);
    Trails.Update();
}

void ParticleTest::UpdatePhysics()
{
    Position = Position + Velocity;

    //Simulate physics
    Velocity = Velocity.Add(Vector3D(0,1.0/100.0,0));
}

