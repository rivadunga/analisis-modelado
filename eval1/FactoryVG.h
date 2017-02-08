#include "Videogame.h"

class FactoryVG
{
public:
    virtual Videogame* createVG(int type) = 0;
public:
};

class ConcreteFactoryVG : public FactoryVG
{
public:
    virtual Videogame* createVG(int type)
    {
        switch (type) {
            case 1:
                return new VGStrategy;
                break;
            case 2:
                return new VGAdventure;
                break;
            case 3:
                return new VGLearning;
                break;
        }
    }
};
