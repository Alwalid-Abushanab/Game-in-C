#pragma once

class World; //forward declaration

class Player
{
    private:
        float health, x,y;
        const int damage = 100;

    public:
        //constructor for the Player class
        Player(float const hp, float const xPos, float const yPos); 
        
        //a method to attack the enemies
        void update(World* world) const;
};
