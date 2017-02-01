#include <iostream>
using namespace std;


//Personaje

class Personaje
{
public:
virtual void correr()       = 0;
virtual Personaje* clonar() = 0;
};

template <class SubClase>
class ClonPersonaje : public Personaje
{
public:
virtual Personaje* clonar()
{
    return new SubClase(dynamic_cast<SubClase&>(*this));
}
};

class Principe : public ClonPersonaje<Principe>
{
public:
void seleccionarArma();
void atacar();
void correr()
{
    cout << "El principe corre rápido" << endl;
}
};

class Princesa : public ClonPersonaje<Princesa>
{
public:
void gritar();
void correr()
{
    cout << "La princesa corre medio lento" << endl;
}
};

class Villano : public ClonPersonaje<Villano>
{
public:
void atacar();
void atraparPricnesa();
void correr()
{
    cout << "El villano no necesita correr" << endl;
}
};

class VillanoVolador : public ClonPersonaje<VillanoVolador>
{
public:
void correr()
{
    cout << "También puede volar" << endl;
}
};

//Factory singleton

class Factory
{
private:
Factory()
{
}
public:
static Factory& getInstance()
{
    static Factory instance;
    return instance;
}
Personaje* build(int type)
{
    switch (type)
    {
    case 1:
        return new Principe;

    case 2:
        return new Princesa;

    case 3:
        return new Villano;

    case 4:
        return new VillanoVolador;
    }
}
};

int main()
{
    Factory   cf   = Factory::getInstance();
    Personaje * pe = cf.build(4);

    pe->correr();
    return 0;
}
