#pragma once
#include <iostream>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include "../rule/Rules.hpp"
#include "Math.hpp"

class Application
{
public:
	Application(int argc, char** argv);
	~Application();
	
private:
	void run();
	void initialize();
	void handleEvents();
	void update(sf::Time & deltaTime);
	void render();

	bool m_running, m_active;

	sf::RenderWindow m_window;

	sf::Font m_font;

	sf::Vector2i m_oldMousePosition;
	
	char* m_path;

	Rules m_rules;

	sf::VertexArray m_lines;

	sf::Vector2f m_position;
	
	float m_angle;

	void followRules();
};
