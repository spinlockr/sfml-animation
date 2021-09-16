#include <SFML/Graphics.hpp>
#include <iostream>

int main(){

    //Variables 
    bool isMovingRight, isMovingLeft, isMovingUp, isMovingDown, isAttacking = false;
    sf::Clock moveRightClock, moveLeftClock, moveUpClock, moveDownClock, moveAttackClock;

    //Window
    sf::RenderWindow window(sf::VideoMode(648, 648), "Movement");
    window.setKeyRepeatEnabled(false);
    sf::Event event;

    //Player
    sf::Texture playerTexture; playerTexture.loadFromFile("advent.png");
    sf::IntRect playerRect( 0, 38, 50, 40 );
    sf::Sprite  playerSprite(playerTexture, playerRect);
    playerSprite.setOrigin(-100, -325);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while (window.isOpen())
    {
        while (window.pollEvent(event)){
            
            if (event.type == sf::Event::Closed) window.close(); //Close Window  
            
            if (event.type == sf::Event::KeyPressed){ 
                
                // if(event.key.code == sf::Keyboard::Right){    
                //     isMovingRight = true; 
                //     moveRightClock.restart(); 
                //     std::cout<<"Right Press"<<std::endl;
                // }//Right Key Press 

                if (event.key.code == sf::Keyboard::Left) { 
                    isMovingLeft = true; 
                    moveLeftClock.restart(); 
                    std::cout<<"Left Press"<<std::endl;
                }//Left Key Press 

            }//Key Pressed Events

            if(event.type == sf::Event::KeyReleased){
                
                if(event.key.code == sf::Keyboard::Right){
                    isMovingRight = false; 
                    playerRect.left = 0;
                    playerSprite.setTextureRect(playerRect);
                    std::cout<<"Right Relase"<<std::endl;
                }//Right Key Release

             if(event.key.code == sf::Keyboard::Left) { 
                    isMovingLeft = false; 
                    playerRect.left = 0;
                    playerSprite.setTextureRect(playerRect);  
                    std::cout<<"Left Relase"<<std::endl;
   
                }//Right Key Release
            
            }//Key Relased Events 
            
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////

        
        if (isMovingRight && moveRightClock.getElapsedTime().asSeconds() > 0.05) { 
            
            playerRect.left += 50;
            if (playerRect.left == 350){
                playerRect.left = 50;
            }

            playerSprite.move(3, 0); 
            playerSprite.setTextureRect(playerRect);
            moveRightClock.restart(); 

            std::cout<<"Moving Right = True"<<std::endl; 
        };//isMovingRight = true

       
        if (isMovingLeft && moveLeftClock.getElapsedTime().asSeconds() > 0.05) { 
            
            playerRect.left += 50;
            if (playerRect.left == 350){
                playerRect.left = 50; 
            }

            playerSprite.move( -3, 0 ); 
            playerSprite.setTextureRect(playerRect);
            moveLeftClock.restart();  

            std::cout<<"Moving Left = True"<<std::endl; 
        };//isMovingLeft = true

        window.clear();
        window.draw(playerSprite);   
        window.display();
    }
    return 0;
}


// sf::Vector2f playerPos;
// playerPos = playerSprite.getPosition();
// std::cout << playerPos.x << std::endl;
// std::cout << playerPos.y << std::endl;

/* if ( playerPos.x >= 100 ){
playerRect.left = 0;  
playerSprite.setTextureRect(playerRect);
playerSprite.setPosition(0.0f,0.0f);
isMovingRight = false; 
}*/






// sf::Texture backTexture; backTexture.loadFromFile("demo.jpg");
// sf::IntRect backRect( 0,0 ,648 ,648 );
// sf::Sprite backSprite(backTexture, backRect);

//window.draw(backSprite);