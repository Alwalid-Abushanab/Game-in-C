#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "world.h"
#include "enemy.h"
#include "player.h"

int main(){
    srand(time(NULL));//randomise the rand function

    int const MaxEnemies = 300;//number of Enemies
    
    World* world  = new World(MaxEnemies);
    
    for(int i = 0; i < MaxEnemies; i++)
    {
        //choose a type randomly
        int randType = rand() % 3;
        //random health
        float health = (rand() % 151) + 50;
        //random x and y coordinates
        float x = (rand() % 201) - 100;
        float y = (rand() % 201) - 100;

        Enemy* pEnemy = nullptr;

        if(randType == 0)
        {
            pEnemy = new Soldier(health,x,y);
        }
        else if (randType == 1)
        {
            pEnemy = new Ninja(health,x,y);
        }
        else{
            pEnemy = new Pirate(health,x,y);
        }

        world->addEnemy(pEnemy); //add the enemy to the world
    }

    //create a player and add it to the world
    Player* player = new Player(200,0,0);

    world->setPlayer(player);

    while(true)
    {
        world->getPlayer()->update(world);

        if(world->getEnemy(MaxEnemies-1)->isDead())
        {
            printf("my Work Here is done\n");
            break;
        }
    }
}