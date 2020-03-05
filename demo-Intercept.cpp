#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Intercept.cpp"
#include <string.h>
using namespace std;

int main()
{
    Intercept<int> stepper(1 ,2);
    Intercept<int> gatherer(0, 3);

    scanf("%d", &stepper);

    for(stepper; stepper > 0; stepper--){
        gatherer += stepper * 2;
    }




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
