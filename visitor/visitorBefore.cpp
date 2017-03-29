#include <iostream>

using namespace std;

class Number
{
public:
    virtual void add() = 0;
    virtual void count() = 0;
};

class Integer : public Number
{
    static int countInts;
public:
    void add()
    {
        countInts++;    
    }
    void count()
    {
        cout << countInts;
    }
};
int Integer::countInts=0;
class Double : public Number
{
    static int countDouble;
public:
    void add()
    {
        countDouble++;    
    }
    void count()
    {
        cout << countDouble;
    }
};
int Double::countDouble=0;

int main()
{
    Number* n[] ={new Integer, new Double};
    
    for(int i=0; i< 5; i++)
    {
        for (int j = 0; j < 2; j++) 
        {
            n[j]->add();    
        }
    }
    
    n[1]->count();
    n[0]->count();
}