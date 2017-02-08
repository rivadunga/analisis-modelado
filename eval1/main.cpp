#include <iostream>
#include <string>
#include "Store.h"
#include "Videogame.h"
using namespace std;


int main()
{
    Store store;

    int   option;

    do
    {
        cout << "O: ";
        cin >> option;

        switch (option)
        {
        //Initialize
        case 1: {
            int maxSize;
            cin >> maxSize;
            store.createInv(maxSize);
        } break;

        //Add videogame
        case 2: {
            string name;
            int    price;
            int    type;
            cin >> name >> price >> type;
            store.addVG(name, price, type);
        } break;

        //Delete vg
        case 3: {
            string name;
            cin >> name;
            store.deleteVG(name);
        } break;

        //Undo delete
        case 4: {
            store.undoDelete();
        } break;

        //Sort videogames (asc, desc)
        case 5: {
            bool asc;
            cin >> asc;
            store.sortInv(asc);
        } break;

        //Find and print videogame
        case 6: {
            string name;
            cin >> name;
            cout << *store.findVG(name);
        } break;

        //Print size
        case 7: {
            cout << store.getSize() << endl;
        } break;

        //Print all videogames
        case 8: {
            store.printInv();
        } break;

        //Execute change
        case 9: {
            int    operation;
            string name;
            int    percentage;
            cin >> operation >> name >> percentage;
            store.executeOperation(operation, name, percentage);
        } break;
        }
    } while (option != -1);
}
