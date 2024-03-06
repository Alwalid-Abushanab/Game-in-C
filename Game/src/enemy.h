#pragma once
#include <stdio.h>

//types of the Enemies
enum class EnemyType{
    Soldier,
    Pirate,
    Ninja
};

class Enemy
{
    public:
        //a method to print the Enemies information
        void printInfo() const;

        virtual void takeDamage(float const damage); //a method that will be modified by the derieved classes

        //a method to check if the enemy is dead
        bool isDead() const;

        //methods to get the x and y coordinates
        float getX();
        float getY();

    private:
        static int ID;
        int currentID; //the ID of the Enemy
        float health, x, y;
        EnemyType type;

    protected:
        Enemy(EnemyType const enemyType, float const hp, float const xPos, float const yPos); //the constructor for the Enemy class
};

class Soldier: public Enemy
{
    public:
        //a constructor for the Soldier class
        Soldier(float const health, float const xPos, float const yPos);

        //override the takeDamage method
        virtual void takeDamage(float const damage);

};

class Ninja: public Enemy
{
    public:
        //a constructor for the Ninja class
        Ninja(float const health, float const xPos, float const yPos);

        //override the takeDamage method
        virtual void takeDamage(float const damage);
};

class Pirate: public Enemy
{
    public:
        //a constructor for the Pirate class
        Pirate(float const health, float const xPos, float const yPos);

        //override the takeDamage method
        virtual void takeDamage(float const damage);
};