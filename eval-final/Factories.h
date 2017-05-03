#pragma once
#include <map>
#include "Objects.h"

class AbstractFactory
{
public:
  virtual Collider* buildCollider(int type) = 0;
};


class AsteroidFactory : public AbstractFactory
{

private:
  AsteroidFactory(){}

public:
  static AsteroidFactory& getInstance()
  {
    static AsteroidFactory instance;
    return instance;
  }
  Collider* buildCollider(int type)
  {
    Collider* asteroid;
      switch(type){
        case 1:
          asteroid = new StonyAst;
          break;
        case 2:
          asteroid = new IronAst;
          break;
      }
    return asteroid;
  }

};



class PlanetFactory : public AbstractFactory
{

private:
  PlanetFactory(){}

public:
  static PlanetFactory& getInstance()
  {
    static PlanetFactory instance;
    return instance;
  }
  Collider* buildCollider(int type)
  {
    Collider* planet;
      switch(type){
        case 1:
          planet = new DesertPl;
          break;
        case 2:
          planet = new EarthPl;
          break;
      }
    return planet;
  }

};
