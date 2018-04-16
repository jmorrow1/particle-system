#include "Particle.h"

Particle::Particle(float lifespan, float x, float y, float vx, float vy, 
	RectangleShape rectShape, float rotation, float angularSpeed)
{
	this->life = lifespan;
	this->lifespan = lifespan;
	this->pos = Vector2<float>(x, y);
	this->vel = Vector2<float>(vx, vy);
	this->rectShape = rectShape;
	this->rotation = rotation;
	this->angularSpeed = angularSpeed;
}

Particle::~Particle()
{

}

void Particle::update(float dt)
{
	life -= dt;
	pos += vel * dt;
	rotation += angularSpeed * dt;
}

void Particle::draw(RenderWindow& window)
{
	rectShape.setPosition(pos);
	rectShape.setRotation(rotation);

	window.draw(rectShape);
}

bool Particle::isAlive()
{
	return life > 0;
}