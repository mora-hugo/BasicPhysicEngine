#pragma once
#include <vector>

#include "Particle.h"
template<typename T>
class ParticleSystem
{
    // If T is not a child from Particle, the compilator will be angry
    static_assert(std::is_base_of<Particle, T>::value, "T must derive from Particle");
public:
    ~ParticleSystem()
    {
        for(unsigned int i = 0; i < Particles.size(); i++)
        {
            // Remove the particle if it is finished
            delete Particles[i];
            Particles.erase(Particles.begin() + i);
                
        }
    }
    
    T* AddParticle(const Vector3D& Position, const Vector3D& Velocity, const double Size, const double Mass,const double Duration)
    {
        T * Particle = new T(Position,Velocity,Size,Mass,Duration);
        Particles.push_back(Particle);
        return Particle;
    }
    
    void Update()
    {
        for(unsigned int i = 0; i < Particles.size(); i++)
        {
            T* CurrentParticle = Particles[i];
            CurrentParticle->Update();
            if(CurrentParticle->IsFinished())
            {
                // Remove the particle if it is finished
                delete Particles[i];
                Particles.erase(Particles.begin() + i);
            }
                
        }
    }
    
    void Draw()
    {
        for(T* CurrentParticle : Particles)
        {
            CurrentParticle->Draw();
        }
    }

private:
    
    std::vector<T*> Particles;
    

    
};
