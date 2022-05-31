#include "Random.h"

using namespace std;

int Random()
{
    random_device rd;
    minstd_rand end(rd());
    uniform_int_distribution<int> uid(0, 99);

    return uid(end);
}
