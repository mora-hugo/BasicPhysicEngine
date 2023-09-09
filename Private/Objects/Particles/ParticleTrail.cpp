#include "../../../Public/Objects/Particles/ParticleTrail.h"

#include "ofGraphics.h"

ParticleTrail::ParticleTrail(const Vector3D& BasePosition, const Vector3D& BaseVelocity, const double& Mass, const double& Size,
                             const double& Duration) : Particle(BasePosition,BaseVelocity,Mass,Size,Duration)
{
    
}

void ParticleTrail::Draw()
{
    Particle::Draw();
}

void ParticleTrail::Update()
{
    
    Particle::Update();
}

void ParticleTrail::UpdatePhysics()
{
    Position = Position + Velocity - ofRandomf() * 0.5;

    //Simulate physics
    Velocity = Velocity.Add(Vector3D(0,Mass/100,0));
}
