#include "LinearVelocity.h"

LinearVelocity::LinearVelocity(float startSpeed, float endSpeed)
{
	this->startSpeed = startSpeed;
	this->endSpeed = endSpeed;
}

void LinearVelocity::execute(Particle* p)
{
	float amt = p->life / p->lifespan;
	float speed = startSpeed + amt * (endSpeed - startSpeed);
	float angle = atan2(p->vel.y, p->vel.x);
	Vector2f acc = Vector2f(speed * cos(angle), speed * sin(angle));
	p->vel += acc;
}