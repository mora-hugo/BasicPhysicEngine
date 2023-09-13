#pragma once
#include "of3dPrimitives.h"
#include "Particle.h"
#include "ParticleSystem.h"
#include "ParticleTrail.h"
#include "../../Math/Vector/Vector3D.h"
class ParticleFireball : public Particle
{
public:
   
   ParticleFireball(const Vector3D& BasePosition, const Vector3D &BaseVelocity, const double &Size, const double& Mass, const double& Duration);
   virtual ~ParticleFireball();
   void Draw() override;
   void Update() override;

   void UpdatePhysics() override;
private:
   double TrailsParticleMass = 5;
   ParticleSystem<ParticleTrail> Trails;



    

    
};
