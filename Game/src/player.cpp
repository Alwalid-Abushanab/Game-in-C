#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "player.h"
#include "world.h"


Player::Player(float const hp, float const xPos, float const yPos): health(hp), x(xPos), y(yPos){}

void Player::update(World* world) const{
    srand(time(NULL));//randomise the rand function

    //iterate through each of the enemies
    for(int i = 0; i < world->getNumEnemies() ; i++){
        //if the enemy is not dead decide what to do
        if(!world->getEnemy(i)->isDead()){
            //a random number between 1 and 10 inclusive
            int dealOrNot = (rand() % 10) + 1; 

            //50% chance to attack the enemy
            if(dealOrNot >= 5){
                double distance = sqrt(pow(fabs(world->getEnemy(i)->getX()),2) + pow(fabs(world->getEnemy(i)->getY()),2));

                //deal damage depending on the distance
                world->getEnemy(i)->takeDamage(damage / (distance * 0.1));

                world->getEnemy(i)->printInfo();
            }

            break;
        }
    }
}