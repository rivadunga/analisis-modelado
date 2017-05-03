#include "Objects.h"
#include "Factories.h"

int main()
{

    /** FIRST SIMULATION BRUTE FORCE **/

	ExplorationSC sc1  = ExplorationSC::getInstance();
	ColonizationSC sc2 = ColonizationSC::getInstance();
	ObservationSC sc3  = ObservationSC::getInstance();

    AsteroidFactory af = AsteroidFactory::getInstance();
	PlanetFactory pf   = PlanetFactory::getInstance();

    Collider* as[] = {
        af.buildCollider(1),
        af.buildCollider(1),
        af.buildCollider(2),
        af.buildCollider(2)
    };

    Collider* pls[] = {
        pf.buildCollider(1),
        pf.buildCollider(1),
        pf.buildCollider(2),
        pf.buildCollider(2)
    };

    //Asteroid collisions
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < 4; i++)
            as[j]->collide(pls[i]);
        as[j]->collide(&sc1);
        as[j]->collide(&sc2);
        as[j]->collide(&sc3);
    }
    cout << endl;

    //Planet collisions
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < 4; i++)
            pls[j]->collide(as[i]);
        pls[j]->collide(&sc1);
        pls[j]->collide(&sc2);
        pls[j]->collide(&sc3);
    }
    cout << endl;

    //Spacecraft collistions
    for (int i = 0; i < 4; i++) sc1.collide(as[i]);
    for (int i = 0; i < 4; i++) sc1.collide(pls[i]);
    for (int i = 0; i < 4; i++) sc2.collide(as[i]);
    for (int i = 0; i < 4; i++) sc2.collide(pls[i]);
    for (int i = 0; i < 4; i++) sc3.collide(as[i]);
    for (int i = 0; i < 4; i++) sc3.collide(pls[i]);

    cout << endl << "--------" << endl << endl;


    /** SECOND SIMULATION OBSERVER**/

    Space* space = Space::getInstance();

    space->attachObserver(&sc1);
    space->attachObserver(&sc2);
    space->attachObserver(&sc3);
    for (int i = 0; i < 4; i++) space->attachObserver(as[i]);
    for (int i = 0; i < 4; i++) space->attachObserver(pls[i]);

    sc1.setRadius(10);
    sc1.setCoords(10,10,10);

    return 0;
}
