#include "Engine.h"

Engine::Engine()
{
	//Default constructor that gets screen size 
	VideoMode vm(1920, 1080);

	//creates game window
	m_Window.create(vm, "Particle!!", Style::Default);
}

void Engine::run()
{
	// clock & time  obj
	Clock clock;
	Time time1;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	//Game loop
	while (m_Window.isOpen())
	{
	    // restarts clokc and returens time as a float of seconds
	    Time time1 = clock.getElapsedTime();
	    clock.restart();

	   // call private member functions
	    input();
	    update(time1.asSeconds());
	    draw();
	}
}
void Engine::input()
{
	int numOfClicks = 0;
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
				for (int i = 0; i < 10; i++)
				{
						Vector2i location(event.mouseButton.x, event.mouseButton.y);

						if(numOfClicks % 2 == 0)
						{
							int x = rand() % 300 + 25;

							Particle spot(m_Window, x, location);
							m_particles.push_back(spot);
						}

						else
						{
							int x = rand() % 101 + 25;

							Particle spot(m_Window, x, location);
							m_particles.push_back(spot);
						}
						numOfClicks++;
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
	Font font;
	if (!font.loadFromFile("arial.ttf")) 
	{cout << "ERROR"<< endl;}

	m_Window.clear();
	
	Text text;
	text.setFont(font);
	text.setColor(sf::Color::White);
	text.setCharacterSize(36);
	text.setString("Pick any spot on the screen to begin!\nThen watch the fun!!");
	m_Window.draw(text);
	
	for(size_t i = 0; i < m_particles.size(); i++)
	{ m_Window.draw(m_particles.at(i)); }

	m_Window.display();
}
