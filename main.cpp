#include <iostream>
#include "Wander.h"

using namespace std;

int main()
{
    Wander w = Wander(10, 10);
    //w.multiSteps(10000);
    w.stopWhenFull();
    w.showInfo();
    return 0;
}
