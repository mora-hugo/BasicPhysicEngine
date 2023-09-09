#pragma once
#include <vector>

#include "Particle.h"
template<typename T>
class ParticleSystem
{
    // If T is not a child from Particle, the compilator will be angry
    static_assert(std::is_base_of<Particle, T>::value, "T must derive from Particle");
public:

    void AddParticle(const Vector3D& Position, const Vector3D& Velocity, const double Size, const double Duration)
    {
        
        Particles.push_back(T(Position,Velocity,Size,Duration));
    }
    
    void Update()
    {
        for(unsigned int i = 0; i < Particles.size(); i++)
        {
            T& CurrentParticle = Particles[i];
            CurrentParticle.Update();
            if(CurrentParticle.IsFinished())
                // Remove the particle if it is finished
                Particles.erase(Particles.begin() + i);
        }
    }
    
    void Draw()
    {
        for(T& CurrentParticle : Particles)
        {
            CurrentParticle.Draw();
        }
    }

private:
    
    std::vector<T> Particles;

    
};
