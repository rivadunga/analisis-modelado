#include <iostream>
#include <string>
#include <stdlib.h>
#pragma once
using namespace std;

//Main class
class Videogame
{
protected:
    int _id;
    string _name;
    int _price;
    int _rating;

public:
    Videogame()
    {
        _id = rand();
    }
    virtual Videogame* clonar() = 0;
    void print()
    {
        cout << _id << endl;
        cout << _name << endl;
        cout << _price << endl;
        cout << _rating << endl;
    }
    int getId(){
        return _id;
    }
    void setName(string name){
        _name = name;
    }
    void setPrice(int price){
        _price = price;
    }
    string getName(){
        return _name;
    }
    int getPrice(){
        return _price;
    }

    friend ostream& operator<<(ostream& os, const Videogame& vg)
    {
        os << vg._id << ' / ' << vg._name << ' / ' << vg._price << endl;
    }

    friend bool operator<(Videogame const & vg, Videogame const & vg1)
    {
        return vg._price < vg1._price;
    }
};

//Videogame copy
template <class T>
class VideogameCopy : public Videogame
{
public:
    virtual Videogame* clonar()
    {
        return new T(dynamic_cast<T&>(*this));
    }
};

class VGStrategy : public VideogameCopy<VGStrategy>
{
private:
    int _players;
public:
    void printV()
    {
        print();
        cout << _players << endl;
    }
};


class VGAdventure : public VideogameCopy<VGAdventure>
{
    private:
        int _worlds;
    public:
        void printV()
        {
            print();
            cout << _worlds << endl;
        }
};


class VGLearning : public VideogameCopy<VGLearning>
{
private:
    string _topic;
public:
    void printV()
    {
        print();
        cout << _topic << endl;
    }
};
