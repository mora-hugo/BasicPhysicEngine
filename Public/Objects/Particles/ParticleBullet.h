#pragma once
#include "of3dPrimitives.h"
#include "Particle.h"
#include "ParticleSystem.h"
#include "ParticleTrail.h"
#include "../../Math/Vector/Vector3D.h"
class ParticleBullet : public Particle
{
public:
   
   ParticleBullet(const Vector3D& BasePosition, const Vector3D &BaseVelocity, const double &Size, const double& Mass, const double& Duration);
   virtual ~ParticleBullet();
   void Setup() override;
   void Draw() override;
   void Update() override;

   void UpdatePhysics() override;
private:
   double TrailsParticleMass = 0.1;
   ParticleSystem<ParticleTrail> Trails;

   



    

    
};
