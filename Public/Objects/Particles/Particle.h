#pragma once
#include "of3dPrimitives.h"
#include "../../Math/Vector/Vector3D.h"
class Particle
{
public:
    Particle(const Vector3D& BasePosition, const Vector3D& BaseVelocity, const double& Size, const double& Mass, const double& Duration = 0);
    Particle();

    bool IsFinished();

    virtual void Setup();
    
    virtual void Update();

    virtual void Draw();

    virtual void UpdatePhysics() = 0;
protected:
    
    Vector3D Position, Velocity;

    double Size = 0;

    double Mass = 1;
private:
    double DurationLeft = 0;
    

    

    
};
