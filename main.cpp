#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(800, 600), "DIABEETUS");
    app.setVerticalSyncEnabled(true);

    // Load a sprite to display
    Texture tex1;
    if (!tex1.loadFromFile("textures/evilwilford.png")) return EXIT_FAILURE; // Exit if texture couldn't load.
    Sprite wilford(tex1);
    float wilfordx = 3;
    float wilfordy = 3;

    // Speed of wilford head bob
    float change_wilfordy = .5;

	// Starfield texture
    Texture tex2;
    if (!tex2.loadFromFile("textures/stars.jpg")) return EXIT_FAILURE;
    Sprite starfield(tex2);

    // Starfield needs to start in the middle
    starfield.setPosition(0, -800);

    // Starfield scroll speed
    float starfieldy = 2;


    // Load Boss Music
    Music bossIntro;
    if (!bossIntro.openFromFile("audio/boss1.ogg")) return EXIT_FAILURE;

    Music bossFight;
    if (!bossFight.openFromFile("audio/boss2.ogg")) return EXIT_FAILURE;
    bossFight.setLoop(true);


    //Start the music
    bossIntro.play();


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();
        }


	// Loop music 
	if (bossIntro.getStatus() == Music::Stopped && bossFight.getStatus() == Music::Stopped)
		bossFight.play();


        // Clear screen
        app.draw(starfield);


	// Move sprites
	wilford.move(wilfordx, wilfordy);
	wilfordy += change_wilfordy;

	// Scroll starfield
	starfield.move(0, starfieldy);

	
	// Collision detection
	// If Wilford reaches the right border, send him back to the left.  Vice versa for left.
	Vector2f pos = wilford.getPosition();
	if (pos.x < 0 || pos.x > 680) wilfordx = -wilfordx;

	// This piece defines the head bob
	if (wilfordy < -5 || wilfordy > 5) change_wilfordy = -change_wilfordy;
	
	// Once starfield texture reaches end of the screen, place back to the start.
	pos = starfield.getPosition();
	if (pos.y == 0) starfield.setPosition(0, -800);
	

        // Draw the sprites
        app.draw(wilford);


        // Update the window
		// Everything moved in the functions above will be shown after this line.
        app.display();
    }

    return EXIT_SUCCESS;
}
