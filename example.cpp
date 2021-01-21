#include <iostream>
#include "getNextRungeKuta.h"

using namespace std;

int main()
{
    float args[] = {};
    float yA = getNextRungeKuta(
        0, 1, 0.1, [](float x, float y, float args[]) {
            return x * x * y;
        },
        args);
    float yB = getNextRungeKuta(
        0.1, yA, 0.1, [](float x, float y, float args[]) {
            return x * x * y;
        },
        args);
    cout << yA << " " << yB << endl;
    return 1;
}