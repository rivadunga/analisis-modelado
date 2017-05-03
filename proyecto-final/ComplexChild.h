#pragma once

#include "Complex.h"
using namespace std;

/** Complex example with inheritance */

class ComplexChild : public Complex
{
	public:
		Integer* attr;
    	ComplexChild(){ attr = new (this) Integer; }
    	~ComplexChild(){ delete attr; }
};
