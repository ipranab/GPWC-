Write the SFML-C++ statements for the Game loop/ Application loop to stay in the program until the player want to quit for the Game Timber.
Additionally enable the Esc key to terminate the game loop, when the key is pressed.

  Ans- RenderWindow window(VideoMode(960,540), "my Game");

       while (window.isOpen()) {
       Event event;
       while (window.pollEvent(event)) {
        if (event.type == Event::Closed || 
           (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
            window.close();
          }
      }
      window.clear();
      // Your drawing code here
      window.display();
 }
