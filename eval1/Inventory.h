#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Videogame.h"
#pragma once
using namespace std;

class Inventory
{
private:
    vector<Videogame*> _dataSet;
    vector<Videogame*> _recyclerBin;
    int _maxSize;
    static Inventory* instance;
    Inventory(){}

public:
   //Singleton call
   static Inventory* getInstance()
   {
       if (instance == 0){
         instance = new Inventory();
        }
     return instance;
   }

   void initializeDataSet(int maxSize)
   {
       _maxSize = maxSize;
   }

   void addVG(Videogame* vg)
   {
       _dataSet.push_back(vg);
       if (_dataSet.size() > _maxSize)
            _maxSize = _dataSet.size();
   }

   void undoDelete()
   {
       for (int i = 0; i < _recyclerBin.size(); i++)
            _dataSet.push_back(_recyclerBin[i]);
        _recyclerBin.clear();
   }

   Videogame* deleteVG(string name)
   {
       for (int i = 0; i < _dataSet.size(); i++)
        if (_dataSet[i]->getName() == name){
            _recyclerBin.push_back(_dataSet[i]);
            _dataSet.erase(_dataSet.begin() + i);
        }
   }

   Videogame* findVG(string name)
   {
       for (int i = 0; i < _dataSet.size(); i++)
        if (_dataSet[i]->getName() == name)
            return _dataSet[i];
   }

   void sortDataSet(bool asc)
   {
       //It works by the > operator overload in class videGame
       sort (_dataSet.begin(), _dataSet.end());
       if (!asc)
        reverse(_dataSet.begin(), _dataSet.end());
   }

   int getSize()
   {
       return _dataSet.size();
   }

   void printDataSet()
   {
       for (int i = 0; i < _dataSet.size(); i++)
            //The operator << is also overriden
           cout << *(_dataSet[i]);
   }

   void increasePrice(string name, int percentage)
   {
       Videogame* vg = findVG(name);
       vg->setPrice(vg->getPrice() * (percentage / 100));
   }

  void decreasePrice(string name, int percentage)
  {
      Videogame* vg = findVG(name);
      vg->setPrice(vg->getPrice() * (1-(percentage / 100)));
  }
};

Inventory* Inventory::instance = 0;
