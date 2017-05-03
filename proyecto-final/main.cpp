#include <iostream>
#include "Complex.h"
#include "ComplexChild.h"
#include "Collector.h"
using namespace std;


//First case
Integer* foo()
{
    Integer* newMem = new Integer;
    return newMem;
}

//Second case
vector<Complex*> vo;
void addTemporal(Integer val)
{
	Complex* a = new Complex;
    a->attr1 = val;
    vo.push_back(a);
}

//Seventh case
Integer* foo(Integer& value)
{
    Integer val = value;
    return &val;
}

int main()
{
	
	//First case
	foo();

	//Second case
	Integer s1;
	s1 = 100;
    addTemporal(s1);
    cout << "TEST: " << s1 << endl;
    vo.pop_back();
	
	//Third case
    ComplexChild* child          = new ComplexChild();
    Complex* polimorphicInstance = (Complex*)child;
    delete polimorphicInstance;
    
    //Forth case
    Complex a;
    Complex b = a;
    *(a.attr2) = 5;
    cout << "TEST: " << *(b.attr2) << endl;

    //Firth case
    Complex** array = new Complex*[10];
    array[0] = new Complex;
    delete [] array;

    //Sixth case
    Integer* sub = new Integer[40];
    sub = new Integer[50];
    delete [] sub;
    Integer* three = new Integer[10];
    Integer* four = new Integer[10];
    three[0] = 2;
    three[2] = 10;
    four = three; 
    delete [] three;
    delete [] four;

    //Seventh case
    Integer i1,i2,i3;
	Integer * p;
	i1 = 5;
    i2 = 10;
    i3 = 10;
    p = foo(i3);
    
    Integer k1, k2;
    k1 = 5;
    k2 = 10;
    k1 = k2;
    cout << k1 << " " << k2 << endl;
    
	Collector* collector = Collector::getInstance();
	//Collector before clean
	cout << *collector;
	//Start cleaning
	collector->clean();
};
