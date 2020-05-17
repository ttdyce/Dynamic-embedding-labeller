#include <iostream>
#include <stdio.h>
#include <math.h>
#include "StateIntercept.cpp"
#include <string.h>
using namespace std;

int main()
{
    //dataset input: 6 4 5 20 30 40 80 4 5 20 30 40 80
    int inputs1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
    int count = 0;

    cout << "Program 1 \n";
    /* good sample program 1*/
    Intercept<int> intercepts1[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(0, 1), Intercept<int>(0, 4), Intercept<int>(0, 8)};
    StateIntercept state1(intercepts1, sizeof(intercepts1) / sizeof(intercepts1[0]));

    for (state1[0] = 10; state1[0] > state1[2]; state1[0]--)
    {
        state1[3] = inputs1[count++];

        if (state1[3] < 0)
        {
            state1[4] = 1;
            break;
        }
        state1[1] += state1[3];
    }
    state1[4];

    int inputs2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 101};
    count = 0;
    cout << "Program 2 \n";
    /* good sample program 2*/
    Intercept<int> intercepts2[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(10, 1), Intercept<int>(0, 4), Intercept<int>(0, 8)};
    StateIntercept state2(intercepts2, sizeof(intercepts2) / sizeof(intercepts2[0]));

    for (state2[0] = 0; state2[0] < state2[2]; state2[0]++)
    {
        state2[3] = inputs2[count++];

        if (state2[3] > 100)
        {
            state2[4] = 1;
            break;
        }

        state2[1] += state2[0];
    }
    state2[4];

    int inputs3[] = {377, 265, 3, 0, 852, 60, 80, 90, 5, 365, 45, 30, 33, 15, 68, 50, 70, 945, 80, -1001};
    count = 0;
    cout << "Program 3 \n";
    /* Extreme sample program 1*/
    Intercept<int> intercepts3[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(19, 1), Intercept<int>(0, 4), Intercept<int>(0, 8)};
    StateIntercept state3(intercepts3, sizeof(intercepts3) / sizeof(intercepts3[0]));
    state3[1] = 10;

    for (state3[0] = -1; state3[0] < state3[2]; state3[0]++)
    {
        state3[3] = inputs3[count++];

        if (state3[3] < -1000)
        {
            state3[4] = 1;
            break;
        }
        state3[1] += state3[3];
    }
    state3[4];

    int inputs4[] = {2, 4, 6, 8, 10, 0, 0, 1, 3, 5, 7, 0, 0, 0, 1001};
    count = 0;
    cout << "Program 4 \n";
    /* Extreme sample program 2*/
    Intercept<int> intercepts4[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(-1, 1), Intercept<int>(0, 4), Intercept<int>(0, 8)};
    StateIntercept state4(intercepts4, sizeof(intercepts4) / sizeof(intercepts4[0]));
    state4[0] = 10;

    for (state4[0] = 14; state4[0] > state4[2]; state4[0]--)
    {
        state4[3] = inputs4[count++];

        if (state4[3] > 1000)
        {
            state4[4] = 1;
            break;
        }

        state4[1] += state4[3];
    }
    state4[4];
}
