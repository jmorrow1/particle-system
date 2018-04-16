#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

class Particle
{
private:
	
	
public:
	RectangleShape rectShape;
	Vector2<float> pos;
	Vector2<float> vel;
	float rotation;
	float angularSpeed;
	float life;
	float lifespan;

	Particle(float lifespan, float x, float y, float vx, float vy,
		RectangleShape rectShape, float rotation, float angularSpeed);
	~Particle();
	void update(float dt);
	void draw(RenderWindow& window);
	bool isAlive();
};

