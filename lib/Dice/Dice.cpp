//
// Created by walcz on 17/06/2025.
//

#include "Dice.h"
#include <random>
#include <iostream>

Dice::Dice()
{

}

int Dice::setDieFaces(const int numberOfFaces)
{
    m_numberOfFaces = numberOfFaces;
    if(m_numberOfFaces < 0)
    {
        m_numberOfFaces = 6;
        return 0x0FF10001;
    }
    return 0;
}

int Dice::roll(int &result) const
{
    if(m_numberOfFaces <= 0)
    {
        return 0x0FF10000;
    }
    static std::random_device random;
    static std::mt19937 generator(random());
    std::uniform_int_distribution<> dis(1, m_numberOfFaces);
    result = dis(generator); // Generate a random number between 1 and m_numberOfFaces
    return 0;
}