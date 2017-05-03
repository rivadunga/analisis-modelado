#pragma once

#include <iostream>
#include "Collector.h"
using namespace std;

/** Main object that handle memory issues */

class Object
{
	public:
	
	//Update using a visitor pattern

	void updateAttach()
	{
		//It can be use to complex memory leaks
	}

	void updateDetach()
	{
		delete this;
	}
	
	//Operator overload
   	
   	void* operator new(size_t size)
	{
    	Collector* c = Collector::getInstance();
    	return c->attach(size);
	}

	void* operator new(size_t size, void* parent)
	{
		Collector* c = Collector::getInstance();
    	return c->attach(size, parent);
	}

	void* operator new[](size_t size)
	{
    	Collector* c = Collector::getInstance();
    	return c->attach(size);
	}

	void operator delete(void *p)
	{	
    	Collector* c = Collector::getInstance();
    	c->detach(p);
	}

	void operator delete[](void *p)
	{
    	Collector* c = Collector::getInstance();
    	c->detach((Object*)p);
	}

	friend istream &operator>>(istream  &is, Object &o) { 
        is >> o;
        return is;            
    } 
};

//Example of new base types (JAVA APPROACH)
//It can be Integer, Double, String

class Integer : public Object
{
	private:
		int value;

	public:
	
	//Examples of operator overload	

	void operator = (Integer i)
	{
		value = i.value; 
	}	

	void operator = (int i)
	{
		value = i;
	}	

	void operator += (Integer i)
	{
		value += i.value; 
	}	

	void operator += (int i)
	{
		value += i;
	}	

	friend ostream& operator<<(std::ostream& os, const Integer& i){
		os << i.value;
    	return os;
	}	 
};
