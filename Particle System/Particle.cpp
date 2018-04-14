#include "Particle.h"

Particle::Particle(float lifespan, float x, float y, float vx, float vy, 
	RectangleShape rectShape, float rotation, float angularSpeed)
	: Particle(lifespan, x, y, vx, vy, rectShape, rotation, angularSpeed, 0.1f) {}

Particle::Particle(float lifespan, float x, float y, float vx, float vy,
	RectangleShape rectShape, float rotation, float angularSpeed, float fadeOutSpeed)
{
	this->life = lifespan;
	this->pos = Vector2<float>(x, y);
	this->vel = Vector2<float>(vx, vy);
	this->rectShape = rectShape;
	this->fadeOutSpeed = fadeOutSpeed;
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
	color.a -= fadeOutSpeed;
	if (color.a < 0) color.a = 0;
}

void Particle::draw(RenderWindow& window)
{
	Transform transform;
	transform = transform.Identity;
	transform.translate(pos);
	transform.rotate(rotation);

	Vector2<float> pt = Vector2<float>(0, 0);
	pt = transform.transformPoint(pt);

	rectShape.setPosition(pt);

	window.draw(rectShape);
}

bool Particle::isAlive()
{
	return life > 0;
}