#pragma once
#include "Particle.h"

class ParticleTrail : public Particle
{
public:
    ParticleTrail(const Vector3D& BasePosition, const Vector3D &BaseVelocity, const double &Size, const double& Mass, const double& Duration);
    void Draw() override;
    void Update() override;
    void UpdatePhysics() override;
};

