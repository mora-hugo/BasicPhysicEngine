#include "../../../Public/Objects/Particles/Particle.h"

#include "of3dGraphics.h"

Particle::Particle(const Vector3D& BasePosition, const Vector3D &BaseVelocity, const double &Size, const double& Mass, const double& Duration) : Position(BasePosition), Velocity(BaseVelocity), Size(Size), Mass(Mass), DurationLeft(Duration)
{
    
}

Particle::Particle()
{
}

bool Particle::IsFinished()
{
    return DurationLeft <= 0;
}

void Particle::Setup()
{
   
}

void Particle::Update()
{
    UpdatePhysics();
    DurationLeft -= ofGetLastFrameTime(); 
    
}

void Particle::Draw()
{
    ofDrawSphere(Position, Size);
}

