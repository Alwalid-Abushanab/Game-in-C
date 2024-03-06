#include <stdio.h>
#include "enemy.h"


int Enemy::ID = 0;//initilize the static ID variable to 0

void Enemy::printInfo() const{

    printf("Enemy [%d] is a ", currentID);
    
    if(type == EnemyType::Soldier)
    {
        printf("Soldier");
    }
    else if(type == EnemyType::Ninja)
    {
        printf("Ninja");
    }
    else if(type == EnemyType::Pirate)
    {
        printf("Pirate");
    }
    
    printf(" with %.2f health\n", health);
}

void Enemy::takeDamage(float const damage){
    health -= damage;

    //make sure the health does not go below 0
    if(health < 0)
    {
        health = 0;
    }
}   

bool Enemy::isDead() const{
    return health == 0;

}


Enemy::Enemy(EnemyType const enemyType, float const hp, float const xPos, float const yPos) : health(hp), x(xPos), y(yPos), type(enemyType){
    ID++;
    //give the current enemy an ID
    currentID = ID;
}

float Enemy::getX(){
    return y;
}

float Enemy::getY(){
    return x;
}


//create an Enemy Soldier 
Soldier::Soldier(float const health, float const xPos, float const yPos) : Enemy(EnemyType::Soldier, health, xPos, yPos){}

//override the takeDamage method
void Soldier::takeDamage(float const damage){
    //call the Enemy class takeDamage method
    Enemy::takeDamage(damage);

    if(isDead()){
        printf("My death shall not go in vein\n");
    }
    else{
        printf("you parely scratched me\n");
    }
}

//create an Enemy Ninja 
Ninja::Ninja(float const health, float const xPos, float const yPos) : Enemy(EnemyType::Ninja, health, xPos, yPos){}

//override the takeDamage method
void Ninja::takeDamage(float const damage){
    //call the Enemy class takeDamage method
    Enemy::takeDamage(damage);

    if(isDead()){
        printf("Ninja died\n");
    }
    else{
        printf("Ninga was hit\n");
    }
}

//create an Enemy Pirate 
Pirate::Pirate(float const health, float const xPos, float const yPos) : Enemy(EnemyType::Pirate, health, xPos, yPos){}

//override the takeDamage method
void Pirate::takeDamage(float const damage){
    //call the Enemy class takeDamage method
    Enemy::takeDamage(damage); 

    if(isDead()){
        printf("my tresures shall be yours\n");
    }
    else{
        printf("arrrr\n");
    }
}