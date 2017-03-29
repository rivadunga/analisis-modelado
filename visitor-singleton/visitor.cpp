#include<iostream>
#include<map>

using namespace std;

class Visitor;
class Number
{
protected:
    string quienSoy;
public:
    string getQuienSoy(){return quienSoy;}
    virtual void accept(Visitor*) = 0;
};

class Integer : public Number
{
public:
    Integer()
    {
        quienSoy = "Integer";
    }
    static int countInts;
    void accept(Visitor*);
};
int Integer::countInts = 0;
class Double : public Number
{
public:
    Double()
    {
        quienSoy = "Double";
    }
    static int countDouble;
    void accept(Visitor*);
};
int Double::countDouble = 0;


class Visitor
{
public:
    virtual void visit(Integer*) = 0;
    virtual void visit(Double*) = 0;
};

class PresentVisitor : public Visitor
{
public:
    void visit(Integer* i)
    {
        cout << i->getQuienSoy();
    }
    void visit(Double* d)
    {
        cout << d->getQuienSoy();
    }
};
class CountVisitor : public Visitor
{
public:
    void visit(Integer* i)
    {
        cout << Integer::countInts;
    }
    void visit(Double* i)
    {
        cout << Double::countDouble;
    }
};

class AddVisitor : public Visitor
{
public:
    void visit(Integer*)
    {
        Integer::countInts++;
    }
    void visit(Double*)
    {
        Double::countDouble++;
    }
};

void Double::accept(Visitor* v)
{
    v->visit(this);
}

void Integer::accept(Visitor* v)
{
    v->visit(this);
}


//SINGLETON IMPORTANT

class Visitors
{
static map<int,Visitor*>* dataSet;

public:
  static init()
  {
    dataSet = new map<int,Visitor*>;
  }
  static Visitor* getInstance(int type)
  {
    Visitor* visitor = (*dataSet)[type];
    if (visitor == 0){
        switch(type){
          case 1:
            visitor = new AddVisitor;
            break;
          case 2:
            visitor = new CountVisitor;
            break;
          case 3:
            visitor = new PresentVisitor;
            break;
        }
        (*dataSet)[type] = visitor;
    }
    return visitor;
  }
};
map<int,Visitor*>* Visitors::dataSet = 0;

int main()
{
    Visitors::init();
    Visitor* a = Visitors::getInstance(1);
    Visitor* c = Visitors::getInstance(2);
    Visitor* p = Visitors::getInstance(3);

    Number* n[] ={new Integer, new Double};

    for(int i=0; i< 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            n[j]->accept(a);
        }
    }

    n[0]->accept(p);
    n[0]->accept(c);
    cout << endl;
    n[1]->accept(p);
    n[1]->accept(c);
}
