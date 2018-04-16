#pragma once

#include "Strategy.h"
#include "Particle.h"

class LinearScale : public Strategy
{
public:
	LinearScale(float startSize, float endSize);
	virtual void execute(Particle* p);

private:
	float startSize, endSize;
};