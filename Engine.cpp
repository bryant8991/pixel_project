#include "Engine.h"

Engine::Engine()
{
	//Default constructor that gwts screen size and halves it
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);

	//creates game window
	RenderWindow m_Window(vm, "Particle!!", Style::Default);
}

void Engine::run()
{
	// clock & time  obj
	Clock clock;
	Time time1 = clock.getElapsedTime();
	Time time2;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	//Game loop
	while (m_Window.isOpen())
	{
	    // restarts clokc and returens time as a float of seconds
	    Time time2 = clock.restart();
	    float dt = time2.asSeconds();

	   // call private member functions
	    input();
	    update(dt);
	    draw();
	}
}
void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			// Quit the game when the window is closed
			m_Window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "the left button was pressed" << std::endl;
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;

				for (int i = 0; i < 5; i++)
				{
						Vector2i location(event.mouseButton.x, event.mouseButton.y);

						int x = rand() % 51 + 25;

						Particle spot(m_Window, x, location);
						m_particles.push_back(spot);
				}
			}
		}
	}
}

void Engine::update(float dtAsSeconds)
{
	size_t i = 0;
	while(i < m_particles.size())
	{
		if(m_particles.at(i).getTTL() > 0.0)
		{
			m_particles.at(i).update(dtAsSeconds);
			i++;
		}
		else
		{
			m_particles.erase(m_particles.begin() +i);
		}
	}
}
void Engine::draw()
{

	m_Window.clear();

	for(size_t i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles.at(i));
	}

	m_Window.display();
}
