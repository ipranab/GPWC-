Write the SFM-C++ statements to fly the image soa.jpeg across the screen from top center to
buttom of the screen. You can make use of the Sprite class method setScale to set the scale
factors of the sprite object.

  Ans- Texture texture;
       texture.loadFromFile("soa.png");

       Sprite sprite;
       sprite.setTexture(texture);
       sprite.setPosition(480,0);

       Clock clock;
       float speed= 100.0f;

       while (window.isOpen()){
         float dt=clock.restart().clock.asSeconds();

         Event event;
         while(window.pollEvent(event)){
           if(event.type==Event::Closed)
             window.close();
         }
         sprite.move(0,speed*dt);
         window.clear();
         window.draw(sprite);
         window.display();
       }
