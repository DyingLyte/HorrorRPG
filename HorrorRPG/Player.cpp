#include "Player.h"
#include <iostream>

Player::Player(double sanity, double durability, double observation)
    : sanity(sanity), durability(durability), observation(observation) {
}

bool Player::sanityCheck(int s)
{
    if (sanity > s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::durabilityCheck(int d)
{
    if (durability > d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::obserCheck(int o)
{
    if (observation > o)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Player::displayStats() const
{
    std::cout << "Sanity:      " << sanity << "\n";
    std::cout << "Durability:  " << durability << "\n";
    std::cout << "Observation: " << observation << "\n";
    std::cout << "-------------------------\n";
}

