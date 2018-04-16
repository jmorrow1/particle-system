#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Particle.h"
#include "Strategy.h"

using namespace sf;

class ParticleSystem
{
private:
	Strategy* strategy;
	Texture* texture;
	std::vector<Particle> particles;
	Vector2<float> emissionPoint;
	float minEmissionAngle;
	float maxEmissionAngle;
	float emissionSpeed;
	float particlesPerSecond;
	float clock;
	float random(float min, float max);

public:
	ParticleSystem(float emissionPtX, float emissionPtY, float emissionSpeed,
		float minEmissionAngle, float maxEmissionAngle, float particlesPerSecond,
		Texture* texture, Strategy* strategy);
	~ParticleSystem();
	void update(float dt);
	void draw(RenderWindow& window);
};

