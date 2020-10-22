#ifndef RAYS_H
#define RAYS_H

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class ray
{
public:
	ray(sf::Vector3f &origin, sf::Vector3f &direction)
		: orig(origin), dir(direction)
	{
	}

	sf::Vector3f origin() { return (orig); }
	sf::Vector3f direction() { return (dir); }

	sf::Vector3f at (float t) {
		return orig + (dir * float(t));
	}

public:
	sf::Vector3f orig;
	sf::Vector3f dir;
};

#endif