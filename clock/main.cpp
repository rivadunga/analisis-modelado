#include <iostream>
#include "Singleton.h"
using namespace std;

int main()
{
    Singleton singleton = Singleton::getInstance();
	singleton.setHour("10:00");
    cout << singleton.getHora() << endl;
}
