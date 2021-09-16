#pragma once


class Agent
{
public:
    unsigned int nbVillager;
    unsigned int nbLumberjack;
    unsigned int nbFood;
    unsigned int nbWood;
    unsigned int nbHouse;
public:
    Agent();
    Agent(const unsigned int nbVillager, const unsigned int nbLumberjack, const unsigned int nbFood, const unsigned int nbWood, const unsigned int nbHouse);
};
