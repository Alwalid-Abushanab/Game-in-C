#include <stdio.h>
#include "world.h"


int World::enemyCounter = 0;

World::World(int const numOfEnemies) : numEnemies(numOfEnemies){
    //array of pointers of enemies
    enemies = new Enemy*[numEnemies];
}

int World::getNumEnemies() const{
    return numEnemies;
}

void World::addEnemy(Enemy* const enemy) const{
    enemies[enemyCounter++] = enemy;
}

Enemy* World::getEnemy(int index) const{
    return enemies[index];
}

void World::setPlayer(Player* cplayer){
    player = cplayer;
}

Player* World::getPlayer() const{
    return player;
}