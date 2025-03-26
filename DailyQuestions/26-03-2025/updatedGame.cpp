//#include <stdafx.h>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
	//Create video mode object
	VideoMode vm(1920, 1080);
	
	//Create & open a window
	RenderWindow window(vm, "Timber", Style::Fullscreen);
	
	//Create an object that will hold a graphics on GPU
	Texture textureBackground;
	
	//load graphics on the texture
	textureBackground.loadFromFile("/home/student/8160_gpwc/project/graphics/background.png");
	
	//Create a sprite
	Sprite spriteBackground;
	
	//Link texture to sprite
	spriteBackground.setTexture(textureBackground);
	
	//set the spritebackground position to cover the screen
	spriteBackground.setPosition(0, 0);
	
	//Load tree texture and create a sprite
	Texture textureTree;
	textureTree.loadFromFile("/home/student/8160_gpwc/project/graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(520, 0);
	
	//Preparing for bee
	Texture textureBee;
	textureBee.loadFromFile("/home/student/8160_gpwc/project/graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	
	//Is the bee currently moving
	bool beeActive = false;
	//How fast the bee can fly
	float beeSpeed = 0.0f;
	
	//Load cloud texture and create three cloud sprites
	Texture textureCloud;
	textureCloud.loadFromFile("/home/student/8160_gpwc/project/graphics/cloud.png");
	
	//3 new sprites will be added 
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	
	//Set cloud positions
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(900, 150);
	spriteCloud3.setPosition(1700, 100);
	
	//Are the clouds curently moving
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	
	//How fast the cloud should be moving
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;
	
	//Preparing for Player
	Texture texturePlayer;
	texturePlayer.loadFromFile("/home/student/8160_gpwc/project/graphics/couragenew.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(1200, 710);
	
	//Preparing for axe
	Texture textureAxe;
	textureAxe.loadFromFile("/home/student/8160_gpwc/project/graphics/axe.png");
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(1065, 820);
	
	//Preparing for log
	Texture textureLog;
	textureLog.loadFromFile("/home/student/8160_gpwc/project/graphics/log.png");
	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(1600, 770);
	
	//Variable to control the time
	Clock clock;
	
	//Adding the time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920/2) - timeBarStartWidth/2, 980);
	
	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;
	
	//Track whether the game is running or not
	bool paused = true;
	
	//Variable for holding score
	int score = 0;
	
	sf::Text messageText;
	sf::Text scoreText;
	
	//Choose fonts
	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	
	//Set the fonts to our message
	messageText.setFont(font);
	scoreText.setFont(font);
	
	//Assign the output message
	messageText.setString("Press ENTER to start!");
	scoreText.setString("Score = 0");
	
	//Setting character size of the font
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	
	//Choose a color
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width/2.0f , textRect.top + textRect.height/2.0f);
	messageText.setPosition(1920/2.0f, 1080/2.0f);
	scoreText.setPosition(20, 20);
	
	//Preparing for branch
	Texture textureBranch;
	textureBranch.loadFromFile("/home/student/8160_gpwc/project/graphics/branch.png");
	Sprite spriteBranch;
	spriteBranch.setTexture(textureBranch);
	spriteBranch.setPosition(820, 400);
	
	
	while (window.isOpen()){
	
		//Handle player input
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
		
		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
			// Reset the time and the score
			score = 0;
			timeRemaining = 5;
		}
		//Updating the scene
		if(!paused){
			Time dt = clock.restart();
			
			//Subtract the amount of time remaining
			timeRemaining -= dt.asSeconds();
			//size up the time bar
			timeBar.setSize(Vector2f(timeBarWidthPerSecond *
				timeRemaining, timeBarHeight));
			
			if (timeRemaining <= 0.0f) {
				// Pause the game
				paused = true;

				// Change the message shown to the player
				messageText.setString("Out of time!!");
	
				//Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top +
					textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
	
			}
				
			if (!beeActive){
				srand((int)time(0));
				beeSpeed = (rand()%200) + 200;  //Bee speed is between 200 and 400
			
				//deciding the height of the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(-100,height);
				beeActive = true;
			}
			else{
				spriteBee.setPosition(spriteBee.getPosition().x + (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
			
				//Check whether bee has reached left hand side of the screen
				if(spriteBee.getPosition().x > 1920){
					beeActive = false;
				}
			}
		
			//Cloud movement
			
			//For cloud 1
			if(!cloud1Active){
				srand((int) time(0) * 10);
				cloud1Speed = (rand() % 200);
				//height of cloud
				srand((int)time(0)*10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;
			}
			else{
				spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
			
				spriteBee.setScale(-1.f, 1.f);  // Flip horizontally to face right	
				
				if (spriteCloud1.getPosition().x > 1920){
					cloud1Active = false;
				}
			}
			//For cloud 2
			if(!cloud2Active){
				srand((int)time(0)*20);
				cloud2Speed = (rand() % 200);
				//height of cloud
				srand((int)time(0)*20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;
			}
			else{
				spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
				
				if (spriteCloud2.getPosition().x > 1920){
					cloud2Active = false;
				}
			}
			//For cloud 3
			if(!cloud3Active){
				srand((int)time(0)*30);
				cloud3Speed = (rand() % 200);
				//height of cloud
				srand((int)time(0)*30);
				float height = (rand() % 450) - 150 ;
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;
			}
			else{
				spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
			
				if (spriteCloud3.getPosition().x > 1920){
					cloud3Active = false;
				}
			}
	
			//Update the score
			std::stringstream ss;
			ss << "Score = " << score;
			scoreText.setString(ss.str());
		}
		//End if(!paused)
		
		//***************************************************************//
		//                         Drawing Board                         //
		//***************************************************************//
		
		window.clear(); //Clear everything from the last frame
		window.draw(spriteBackground);
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		window.draw(spriteTree);
		window.draw(spriteBee);
		window.draw(scoreText);
		
		if(paused){
			window.draw(messageText);
		}
		//Display everything
		window.display();
	}
	return 0;
}

//Compile code : g++ Timber.cpp -o timber -lsfml-window -lsfml-system -lsfml-graphics
