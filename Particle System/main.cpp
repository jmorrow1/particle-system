#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "ParticleSystem.h"

#include <iostream>

using namespace sf;

int main()
{
	// setup
	const int FPS = 60;
	const float SPF = 1.0f / FPS;
	RenderWindow window(VideoMode(800, 600), "Particles");
	Clock clock = Clock();

	Texture* particleTexture = new Texture();
	particleTexture->loadFromFile("Assets/banana.png");
	ParticleSystem* system = new ParticleSystem(400, 300, 20.0f, 0, 6.28f, 50, particleTexture);

	RectangleShape shape;
	shape.setTexture(particleTexture);
	shape.setPosition(400, 300);
	shape.setSize(Vector2<float>(20, 20));

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
			system->update(dt);

			window.clear();
			system->draw(window);

			window.display();
		}
	}

	delete particleTexture;

	return 0;
}