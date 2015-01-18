#include "Application.hpp"

Application::Application(int argc, char** argv)
{
	if (argc > 1)
	{
		m_path = argv[1];
	}

	run();
}

Application::~Application()
{

}

void Application::followRules()
{
	if(m_lines.getVertexCount() == 0)
	{
		m_position = sf::Vector2f(720/3, 0);
	}

	std::string string = m_rules.getString();

	std::cout << string << std::endl;

	for(int i = 0; i < string.size(); ++i)
	{
		switch((char)(string[i]))
		{
		case '+':
			m_angle += 60;
		break;

		case '-':
			m_angle -= 60;
		break;

		case 'F':
		case 'G':
			m_lines.append(sf::Vertex(m_position, sf::Color(100, 100, 100)));
			m_lines.append(sf::Vertex(sf::Vector2f(std::cos(math::toRadians<float>(m_angle))*.35f + m_position.x, std::sin(math::toRadians(m_angle))*.35f + m_position.y), sf::Color(100, 100, 100)));
			
			m_position = m_lines[m_lines.getVertexCount() - 1].position;
		break;
		}
	}
}

void Application::initialize()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 32;

	m_window.create(sf::VideoMode(1280, 720), "L-System", sf::Style::Close, settings);

	m_running = true;
	m_active = true;

	m_angle = 0;

	for(int i = 0; i < 10; ++i)
	{
		m_rules.iterate();
	}

	followRules();

	m_lines.setPrimitiveType(sf::Lines);
}

void Application::run()
{
	initialize();

	sf::Clock dt;
	sf::Time deltaTime;
	sf::Time updateTime = sf::seconds(1.f/60.f);

	while(m_running)
	{
		deltaTime += dt.getElapsedTime();
		dt.restart();

		handleEvents();
		render();
		while (deltaTime >= updateTime && m_active)
		{
			update(deltaTime);
			deltaTime -= updateTime;
		}
	}
}

void Application::handleEvents()
{
	sf::Event event;

	while(m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_running = false;
			}
		}
	}
}

void Application::update(sf::Time & p_deltaTime)
{
}

void Application::render()
{
	m_window.clear(sf::Color(46, 46, 46));
	m_window.draw(m_lines);
	m_window.display();
}
