#include "../../../Public/Objects/Particles/ParticleBullet.h"

#include "ofGraphics.h"

ParticleBullet::ParticleBullet(const Vector3D& BasePosition, const Vector3D& BaseVelocity, const double& Mass, const double& Size,
                             const double& Duration) : Particle(BasePosition,BaseVelocity,Size,Mass,Duration)
{
    const unsigned short NumberOfTrails = 100;
    for(unsigned short i = 0; i < NumberOfTrails; i++)
    {
        const double angleRad = i * 2 * PI / NumberOfTrails /4;
        
        const double Xvalue = Velocity.GetX() * (cos(angleRad) + sin(angleRad));
        const double Yvalue = Velocity.GetY() * (-sin(angleRad) + cos(angleRad));
        
        const Vector3D Vector(0.f, -NumberOfTrails/2,0);
        Trails.AddParticle(Position,(Vector3D(Xvalue,Yvalue)).Negate(),Size,TrailsParticleMass,ofRandomf()+1*0.5);
    }

}

ParticleBullet::~ParticleBullet()
{
}

void ParticleBullet::Setup()
{
    Particle::Setup();
   
}

void ParticleBullet::Draw()
{
    Particle::Draw();
    Trails.Draw();
}

void ParticleBullet::Update()
{
    Particle::Update();
    Trails.Update();
}

void ParticleBullet::UpdatePhysics()
{
    Position = Position + Velocity;
}
