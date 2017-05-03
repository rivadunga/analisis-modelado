#pragma once
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Collider;


//Space is an observer of the collider positions

class Space {

private:
    Space(){
        s_instance = this;
    }
    static Space* s_instance;

protected:
    vector< Collider* > observers;

public:
    static Space* getInstance()
    {
        if (!s_instance)
          s_instance = new Space;
        return s_instance;
    }
    void attachObserver(Collider * observer) {
        observers.push_back(observer);
    }
    void updateCoords(Collider* collider){
        notifyAll(collider);
    }
    void notifyAll(Collider* collider);
};
Space* Space::s_instance = 0;


class Collider
{
protected:
    string type;
    int cx, cy, cz;
    int radius;
public:
    //Visitor pattern
    virtual void collide(Collider*) = 0;

    string getType(){return type;}
    void setCoords(int cx, int cy, int cz)
    {
        this->cx = cx;
        this->cy = cy;
        this->cz = cz;
        Space* s = Space::getInstance();
        s->updateCoords(this);
    }
    void setRadius(int radius)
    {
        this->radius = radius;
    }
    void update(Collider* collider)
    {
        cout << "From: " << type << " - " << collider->getType() << " position was modified" << endl;
    }
};

void Space::notifyAll(Collider* collider)
{
    for (int i = 0; i < observers.size(); i++){
        observers[i]->update(collider);
    }
}

class SpaceCraft : public Collider
{
protected:
    string model;
    int condition;
public:
    SpaceCraft()
    {
        type = "spaceCraft";
        condition = 100;
    }
    string getModel(){return model;}
    int getCondition(){return condition;}
    void collide(Collider* collider)
    {
        cout << "SpaceCraft::" << model << " collides with " << collider->getType() << endl;
    }
};

class ExplorationSC : public SpaceCraft
{
private:
    int reach;
    ExplorationSC()
    {
        model = "exploration";
        reach = 100000;
    }
public:
    static ExplorationSC& getInstance()
    {
          static ExplorationSC instance;
          return instance;
    }
    int getReach(){return reach;}
};

class ColonizationSC : public SpaceCraft
{
private:
    int capacity;
    ColonizationSC()
    {
        model = "colonization";
        capacity = 100;
    }
public:
    static ColonizationSC& getInstance()
    {
          static ColonizationSC instance;
          return instance;
    }
    int getCapacity(){return capacity;}
};


class ObservationSC : public SpaceCraft
{
private:
    int range;
    ObservationSC()
    {
        model = "observation";
        range = 100000;
    }
public:
    static ObservationSC& getInstance()
    {
          static ObservationSC instance;
          return instance;
    }
    int getRange(){return range;}
};


class Asteroid : public Collider
{
protected:
    string material;
public:
    Asteroid()
    {
        type = "asteroid";
    }
    string getMaterial(){return material;}
    void collide(Collider* collider)
    {
        cout << "Asteroid::" << material << " collides with " << collider->getType() << endl;
    }
};

class StonyAst : public Asteroid
{
public:
    StonyAst()
    {
        material = "stony";
    }
};


class IronAst : public Asteroid
{
public:
    IronAst()
    {
        material = "iron";
    }
};


class Planet : public Collider
{
protected:
    int temperature;
public:
    Planet()
    {
        type = "planet";
    }
    int getTemperature(){return temperature;}
    void collide(Collider* collider)
    {
        cout << "Planet::" << temperature << "deg collides with " << collider->getType() << endl;
    }
};

class DesertPl : public Planet
{
public:
    DesertPl()
    {
       temperature = 100;
    }
};


class EarthPl : public Planet
{
public:
    EarthPl()
    {
        temperature = 24;
    }
};
