#include <string>
#include <iostream>
#include "Inventory.h"
#include "FactoryVG.h"
#include "Videogame.h"
#pragma once
using namespace std;

class Store
{
public:
    void createInv(int maxSize)
    {
        Inventory* inv = Inventory::getInstance();
        inv->initializeDataSet(maxSize);
    }

    void addVG(string name, int price, int type)
    {
        FactoryVG* f = new ConcreteFactoryVG;
        Videogame* vg = f->createVG(type);
        vg->setName(name);
        vg->setPrice(price);

        Inventory* inv = Inventory::getInstance();
        inv->addVG(vg);
    }

    void deleteVG(string name)
    {
        Inventory* inv = Inventory::getInstance();
        inv->deleteVG(name);
    }

    void undoDelete()
    {
        Inventory* inv = Inventory::getInstance();
        inv->undoDelete();
    }

    Videogame* findVG(string name){
        Inventory* inv = Inventory::getInstance();
        return inv->findVG(name);
    }

    void sortInv(bool asc)
    {
        Inventory* inv = Inventory::getInstance();
        inv->sortDataSet(asc);
    }

    int getSize()
    {
        Inventory* inv = Inventory::getInstance();
        return inv->getSize();
    }

    void printInv()
    {
        Inventory* inv = Inventory::getInstance();
        inv->printDataSet();
    }

    void executeOperation(int type, string name, int percentage){
        Inventory* inv = Inventory::getInstance();
        if (type == 1)
            inv->increasePrice(name, percentage);
        else inv->decreasePrice(name, percentage);
    }
};
