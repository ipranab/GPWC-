Consider the two SFML classes, Texture and Sprite, that will take care of drawing sprites into
the screen. Use the two classes to draw an image soa.jpeg onto the window of size 960 × 540.

  Ans- Texture texture;
       texture.loadFromFile("soa.png");

       Sprite sprite;
       sprite.setTexture(texture);

       RenderWindow window(VideoMode(960,540), "soaa");

       while(window.isOpen()){
         Event event;
         while(window.pollEvent(event)){
           if(event.type==Event::Closed)
             window.close();
         }
         window.clear();
         window.draw(sprite);
         window.display();
       }
