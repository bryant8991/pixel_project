#include "Engine.h"

Engine::Engine()
{
	//Default constructor that gwts screen size and halves it
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);

	//creates game window
	m_Window(vm, "Particle!!", Style::Default);
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
		/*
		****************************************
		Handle the players input
		****************************************
		*/

		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
		    	// Quit the game when the window is closed
			window.close();
		    }

		    Time time2 = clock.restart();
		    float dt = time2.asSeconds();
		}
}
