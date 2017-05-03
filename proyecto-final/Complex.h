#pragma once

#include "Object.h"
using namespace std;

/** Complex object example */

class Complex : public Object
{
	public:
		Integer attr1;
		Integer* attr2;
    	Complex(){ attr2 = new (this) Integer; }
    	~Complex(){ delete attr2;}
};
