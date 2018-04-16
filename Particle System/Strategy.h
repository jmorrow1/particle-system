#pragma once

#include "Particle.h"

class Strategy
{
	public:
		virtual void execute(Particle* p) = 0;
};