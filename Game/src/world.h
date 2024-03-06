#pragma once
#include "player.h"
#include "enemy.h"

class World
{
    private:
        Enemy** enemies;
        int numEnemies;
        Player* player;
        static int enemyCounter;

    public:
        //constructor for the World class
        World(int const numOfEnemies);

        int getNumEnemies() const;

        void addEnemy(Enemy* const enemy) const;

        Enemy* getEnemy(int const index) const;

        void setPlayer(Player* const cplayer);

        Player* getPlayer() const;
};