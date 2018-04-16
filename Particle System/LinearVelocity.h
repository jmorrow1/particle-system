#pragma once

#include "Strategy.h"
#include "Particle.h"

class LinearVelocity : public Strategy
{
public:
	LinearVelocity(float startSpeed, float endSpeed);
	virtual void execute(Particle* p);

private:
	float startSpeed, endSpeed;
};
