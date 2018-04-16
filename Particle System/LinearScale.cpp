#include "LinearScale.h"

LinearScale::LinearScale(float startSize, float endSize)
{
	this->startSize = startSize;
	this->endSize = endSize;
}

void LinearScale::execute(Particle* p)
{
	float amt = p->life / p->lifespan;
	float size = startSize + amt * (endSize - startSize);
	p->rectShape.setSize(Vector2f(size, size));
}
