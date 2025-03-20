#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // Create a video mode object
    VideoMode vm(1920, 1080);
    // Create and open a window
    RenderWindow window(vm, "Timber", Style::Fullscreen);

    // Create an object that will hold graphics on the GPU
    Texture textureBackground;
    textureBackground.loadFromFile("/home/student/8160_gpwc/project/graphics/background.png");

    // Create a sprite for background
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    // Create a tree sprite
    Texture textureTree;
    textureTree.loadFromFile("/home/student/8160_gpwc/project/graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(200, 0);
    
    // Adding tree2 in the spritesheet
    /*Texture textureTree2;
    textureTree2.loadFromFile("graphics/tree2.png");
    Sprite spriteTree2;
    spriteTree2.setTexture(textureTree2);
    spriteTree2.setPosition(1600, 0);*/
    
    // Adding branch in the spritesheet
    Texture textureBranch;
    textureBranch.loadFromFile("/home/student/8160_gpwc/project/graphics/branch.png");
    Sprite spriteBranch;
    spriteBranch.setTexture(textureBranch);
    spriteBranch.setPosition(500, 300);

    // Adding bee in the spritesheet
    Texture textureBee;
    textureBee.loadFromFile("/home/student/8160_gpwc/project/graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(1000, 150);

    // Adding axe in the spritesheet
    Texture textureAxe;
    textureAxe.loadFromFile("/home/student/8160_gpwc/project/graphics/axe.png");
    Sprite spriteAxe;
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(880, 885);


    // Adding log in the spritesheet
    Texture textureLog;
    textureLog.loadFromFile("/home/student/8160_gpwc/project/graphics/log.png");
    Sprite spriteLog;
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(1600, 770);

    // Adding player in the spritesheet
    Texture texturePlayer;
    texturePlayer.loadFromFile("/home/student/8160_gpwc/project/graphics/couragenew.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(960, 560);

    // Adding rip in the spritesheet
    Texture textureRip;
    textureRip.loadFromFile("/home/student/8160_gpwc/project/graphics/rip.png");
    Sprite spriteRip;
    spriteRip.setTexture(textureRip);
    spriteRip.setPosition(1200, 820);

    // Is the bee currently moving
    bool beeActive = false;
    float beeSpeed = 0.0f;

    // Make 3 cloud sprites in 1 texture
    Texture textureCloud;
    textureCloud.loadFromFile("/home/student/8160_gpwc/project/graphics/cloud.png");

    // 3 new sprites with the same texture
    Sprite spriteCloud1, spriteCloud2, spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    // Position of cloud at different positions
    spriteCloud1.setPosition(0, 50);
    spriteCloud2.setPosition(600, 150);
    spriteCloud3.setPosition(1200, 100);
    
    //Cloud movement speed
    float cloud1Speed=0.0f;
    float cloud2Speed=0.0f;
    float cloud3Speed=0.0f; //cloud moves at this speed
    
    //are the clouds active
    bool cloud1Active=false;
    bool cloud2Active=false;
    bool cloud3Active=false;

    // Clock to handle time-based movement
    Clock clock;

    while (window.isOpen()) {
        // Handle player input
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        // Update the scene
        Time dt = clock.restart();

        // Update the bee's position
        if (!beeActive) {
            srand(int(time(0)));
            beeSpeed = (rand() % 200) + 200;  // Bee speed between 200 and 400

            // Deciding the height of the bee
            srand(int(time(0)) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);  // Spawn the bee at the far right
            beeActive = true;
        } else {
            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
            if (spriteBee.getPosition().x < -100) {
                beeActive = false;  // Reset bee when it moves off screen
            }
        }
        
        //cloud movement
        //for cloud 1
        if(!cloud1Active){
        	srand((int)time(0)*100);
        	cloud1Speed=(rand()%200);
        	//height of cloud
        	srand((int)time(0)*10);
        	float height=(rand()%150);
        	spriteCloud1.setPosition(-200,height);
        	cloud1Active=true;
        }
        else{
        	spriteCloud1.setPosition(spriteCloud1.getPosition().x+(cloud1Speed*dt.asSeconds()),spriteCloud1.getPosition().y);
        	if(spriteCloud1.getPosition().x>1920){
        		cloud1Active=false;
        	}
        }
        
        // cloud2
		if (!cloud2Active) {
			srand((int)time(0) * 100 + 1);  // Modify the seed for each cloud
			cloud2Speed = (rand() % 300);  // Random speed for cloud2
			// height of cloud
			srand((int)time(0) * 10 + 2);  // Modify the seed for each cloud
			float height = (rand() % 150);
			spriteCloud2.setPosition(-200, height);  // Set the cloud position off-screen to the left
			cloud2Active = true;  // Activate cloud2
		} else {
			spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
			if (spriteCloud2.getPosition().x > 1920) {
				cloud2Active = false;  // Deactivate cloud2 once it moves off-screen
			}
		}

		// cloud3
		if (!cloud3Active) {
			srand((int)time(0) * 100 + 3);  // Modify the seed for each cloud
			cloud3Speed = (rand() % 200);  // Random speed for cloud3
			// height of cloud
			srand((int)time(0) * 10 + 4);  // Modify the seed for each cloud
			float height = (rand() % 150);
			spriteCloud3.setPosition(-200, height);  // Set the cloud position off-screen to the left
			cloud3Active = true;  // Activate cloud3
		} else {
			spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
			if (spriteCloud3.getPosition().x > 1920) {
				cloud3Active = false;  // Deactivate cloud3 once it moves off-screen
			}
		}
        
        //Move clouds horizontally
        //spriteCloud1.move(-cloudSpeed*dt.asSeconds(),0);
        //spriteCloud2.move(-cloudSpeed*dt.asSeconds(),0);
        //spriteCloud3.move(-cloudSpeed*dt.asSeconds(),0);
        
        // If cloud moves off screen, reposition it to the right
        //if (spriteCloud1.getPosition().x < -200) spriteCloud1.setPosition(1920, 50);
        //if (spriteCloud2.getPosition().x < -200) spriteCloud2.setPosition(1920, 150);
        //if (spriteCloud3.getPosition().x < -200) spriteCloud3.setPosition(1920, 100);
        

        // Clear everything from the last frame
        window.clear();

        // Draw the scene
        window.draw(spriteBackground);
        window.draw(spriteCloud1);        
        window.draw(spriteTree);
        window.draw(spriteCloud2);
        window.draw(spriteBee);
        window.draw(spritePlayer);
        window.draw(spriteAxe);
        //window.draw(spriteTree2);
        window.draw(spriteCloud3);
        window.draw(spriteBranch);
        window.draw(spriteLog);
        
        window.draw(spriteRip);

        // Show everything we just drew
        window.display();
    }

    return 0;
}
//g++ timber.cpp -o timber -lsfml-window -lsfml-system -lsfml-graphics
