#include <iostream>
#include <stdio.h>
#include <math.h>
#include "StateIntercept.cpp"
#include <string.h>
using namespace std;

int main()
{

    /* state trace labelling demo */
    Intercept<int> intercepts[2] = {Intercept<int>(1, 2), Intercept<int>(0, 3)};
    StateIntercept state(intercepts, 2);
    int in;

    in = 10;
    scanf("%d", &state[0]);


    // state[0] = 20;
    // state[0] = 30;
    // state.logCurrentState();

    for (state[0]; state[0] > 0; state[0]--)
    {
        state[1] += state[0];
    }

    /* variable trace labelling demo */
    // Intercept<int> stepper(1, 2);
    // Intercept<int> gatherer(0, 3);

    // scanf("%d", &stepper);

    // for (stepper; stepper > 0; stepper--)
    // {
    //     gatherer += stepper * 2;
    // }

    /* operator demo */
    // int i = 0;
    // int &k = i;
    // int j = k;
    // k++;

    // printf("i: %d, k: %d, j: %d, ", i, k, j);

    // printf("do int x = 0\n");
    // Intercept<int> x = 0;
    // printf("\n");

    // printf("do = 1\n");
    // x = 1;
    // printf("\n");

    // printf("do += 1\n");
    // x += 1;
    // printf("\n");

    // printf("do x++\n");
    // printf("%d", x++);
    // printf("\n");
    // printf("\n");

    // printf("do ++x\n");
    // printf("%d", ++x);
    // printf("\n");
    // printf("\n");
}
