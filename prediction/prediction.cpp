#include <iostream>
#include <stdio.h>
#include <math.h>
#include "StateIntercept.cpp"
#include <string.h>
using namespace std;

int main()
{

    cout << "Program 1 \n";
    /* good sample program 1*/
    Intercept<int> intercepts1[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(0, 1)};
    StateIntercept state1(intercepts1, sizeof(intercepts1) / sizeof(intercepts1[0]));

    for (state1[0] = 10; state1[0] > state1[2]; state1[0]--)
    {
        state1[1] += state1[0];
    }

    cout << "Program 2 \n";
    /* good sample program 2*/
    Intercept<int> intercepts2[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(10, 1)};
    StateIntercept state2(intercepts2, sizeof(intercepts2) / sizeof(intercepts2[0]));

    for (state2[0] = 0; state2[0] < state2[2]; state2[0]++)
    {
        state2[1] += state2[0];
    }

    cout << "Program 3 \n";
    /* Extreme sample program 1*/
    Intercept<int> intercepts3[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(100, 1)};
    StateIntercept state3(intercepts3, sizeof(intercepts3) / sizeof(intercepts3[0]));
    state3[1] = 10;

    for (state3[0] = -1; state3[0] < state3[2]; state3[0]++)
    {
        state3[1] += state3[0];
    }

    cout << "Program 4 \n";
    /* Extreme sample program 2*/
    Intercept<int> intercepts4[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(-1, 1)};
    StateIntercept state4(intercepts4, sizeof(intercepts4) / sizeof(intercepts4[0]));
    state4[0] = 10;

    for (state4[0] = 100; state4[0] > state4[2]; state4[0]--)
    {
        state4[1] += state4[0];
    }
}
