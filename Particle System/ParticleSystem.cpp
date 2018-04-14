#include "ParticleSystem.h"
#include <iostream>

ParticleSystem::ParticleSystem(float emissionPtX, float emissionPtY, float emissionSpeed,
	float minEmissionAngle, float maxEmissionAngle, float particlesPerSecond, Texture* texture)
{
	this->emissionPoint = *new Vector2<float>(emissionPtX, emissionPtY);
	this->emissionSpeed = emissionSpeed;
	this->minEmissionAngle = minEmissionAngle;
	this->maxEmissionAngle = maxEmissionAngle;
	this->particlesPerSecond = particlesPerSecond;
	this->texture = texture;
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::update(float dt)
{
	// emit particles
	clock += dt;
	int particlesToEmit = (int) (clock * particlesPerSecond);
	clock -= (particlesToEmit / particlesPerSecond);
	//std::cout << particles.size() << std::endl;

	for (int i = 0; i < particlesToEmit; i++)
	{
		float emissionAngle = random(minEmissionAngle, maxEmissionAngle);
		float vx = emissionSpeed * cos(emissionAngle);
		float vy = emissionSpeed * sin(emissionAngle);
		RectangleShape rectShape = RectangleShape();
		rectShape.setTexture(texture);
		rectShape.setSize(Vector2<float>(30, 30));
		float lifespan = random(1, 5);

		Particle p = Particle(lifespan, emissionPoint.x, emissionPoint.y, vx, vy, rectShape);
		particles.push_back(p);
	}

	// update particles
	for (int i = 0; i < particles.size(); i++)
	{
		if (particles[i].isAlive())
		{
			particles[i].update(dt);
		}
		
		if (!particles[i].isAlive())
		{
			particles.erase(particles.begin() + i);
			i--;
		}
	}
}

void ParticleSystem::draw(RenderWindow& window)
{
	for (Particle p : particles)
	{
		p.draw(window);
	}
}

float ParticleSystem::random(float min, float max)
{
	return min + (max - min) * ((float) rand() / RAND_MAX);
}