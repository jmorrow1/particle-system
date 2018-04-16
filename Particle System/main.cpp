#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "ParticleSystem.h"
#include "LinearVelocity.h"
#include "LinearScale.h"

#include <iostream>

using namespace sf;

int main()
{
	// setup
	const int FPS = 60;
	const float SPF = 1.0f / FPS;
	RenderWindow window(VideoMode(800, 600), "Particles");
	Clock clock = Clock();

	Texture* bananaTexture = new Texture();
	bananaTexture->loadFromFile("Assets/banana.png");

	Texture* cabbageTexture = new Texture();
	cabbageTexture->loadFromFile("Assets/cabbage.png");

	ParticleSystem* bananaSystem = new ParticleSystem(200, 300, 20.0f,
		3, 6, 50, bananaTexture, new LinearVelocity(0.05, 0.5));

	ParticleSystem* cabbageSystem = new ParticleSystem(600, 300, 20.0f,
		0, 6.28, 25, cabbageTexture, new LinearScale(5, 50));

	// run
	while (window.isOpen())
	{
		// check window events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		// run game loop
		float dt = clock.getElapsedTime().asSeconds();
		if (dt >= SPF)
		{
			clock.restart();
			bananaSystem->update(dt);
			cabbageSystem->update(dt);

			window.clear();
			bananaSystem->draw(window);
			cabbageSystem->draw(window);

			window.display();
		}
	}

	delete bananaTexture;

	return 0;
}