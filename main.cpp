#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;


int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    app.setVerticalSyncEnabled(true);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("evilwilford.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Move sprite distance
    float spritex = 3;

    // Load Boss Music
    Music bossIntro;
    if (!bossIntro.openFromFile("boss1.ogg")) return EXIT_FAILURE;

    Music bossFight;
    if (!bossFight.openFromFile("boss2.ogg")) return EXIT_FAILURE;
    bossFight.setLoop(true);

    //Play the boss intro
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

	if (bossIntro.getStatus() == Music::Stopped && bossFight.getStatus() == Music::Stopped)
		bossFight.play();

        // Clear screen
        app.clear(Color::Black);

	// Move sprite
	sprite.move(spritex, 0);

	// Enemy wall collision detection
	Vector2f pos = sprite.getPosition();
	if (pos.x > 680 || pos.x < 0) spritex = -spritex;
	

        // Draw the sprite
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
