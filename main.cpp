#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "DIABEETUS");
    app.setVerticalSyncEnabled(true);

    // Load a sprite to display
    sf::Texture tex1;
    if (!tex1.loadFromFile("evilwilford.png")) return EXIT_FAILURE;
    sf::Sprite wilford(tex1);
    float wilfordx = 3;

    sf::Texture tex2;
    if (!tex2.loadFromFile("stars.jpg")) return EXIT_FAILURE;
    sf::Sprite starfield(tex2);

    // Starfield needs to start in the middle
    starfield.setPosition(0, -800);

    // Starfield scroll speed
    float starfieldy = 2;


    // Load Boss Music
    Music bossIntro;
    if (!bossIntro.openFromFile("boss1.ogg")) return EXIT_FAILURE;

    Music bossFight;
    if (!bossFight.openFromFile("boss2.ogg")) return EXIT_FAILURE;
    bossFight.setLoop(true);


    //Start the music
    bossIntro.play();


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }


	// Loop music 
	if (bossIntro.getStatus() == Music::Stopped && bossFight.getStatus() == Music::Stopped)
		bossFight.play();


        // Clear screen
        app.draw(starfield);


	// Move sprites
	wilford.move(wilfordx, 0);
	starfield.move(0, starfieldy);

	
	// Collision detection
	Vector2f pos = wilford.getPosition();
	if (pos.x > 680 || pos.x < 0) wilfordx = -wilfordx;
	
	pos = starfield.getPosition();
	if (pos.y == 0) starfield.setPosition(0, -800);
	

        // Draw the sprites
        app.draw(wilford);


        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
