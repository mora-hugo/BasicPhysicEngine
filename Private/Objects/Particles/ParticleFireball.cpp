#include "..\..\..\Public\Objects\Particles\ParticleFireball.h"

#include "of3dGraphics.h"
#include "ofGraphics.h"
ParticleFireball::ParticleFireball(const Vector3D& BasePosition, const Vector3D &BaseVelocity, const double &Size, const double& Mass, const double& Duration) : Particle(BasePosition,BaseVelocity,Size,Mass,Duration)
{
    
}
void ParticleFireball::Draw()
{
    ofSetColor(ofColor::blue);
    Particle::Draw();
    Trails.Draw();
    
}

void ParticleFireball::Update()
{
    Particle::Update();
    Trails.AddParticle(Position,Velocity.Negate().Multiply(ofRandom(0.1,0.5)),Size-5,TrailsParticleMass,ofRandomf()+1*0.5);
    Trails.Update();
}

void ParticleFireball::UpdatePhysics()
{
    Position = Position + Velocity;

    //Simulate physics
    Velocity = Velocity.Add(Vector3D(0,Mass/100,0));
}

ParticleFireball::~ParticleFireball()
{
    
}
