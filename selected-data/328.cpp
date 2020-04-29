#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> Divide(Intercept<int> a, Intercept<int> b);
int main()
{
    Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> Times = 0;
    // Intercept<int> Num = 0;
    // Intercept<int> i(0, 2);
    Intercept<int> Temp[100] = {0};
    cin >> state[1];
    for (state[0] = 0; state[0] < state[1]; state[0]++)
    {
        cin >> state[2];
        Temp[state[0]] = Divide(state[2], state[2]);
    }
    for (state[0] = 0; state[0] < state[1]; state[0]++)
    {
        cout << Temp[state[0]] << endl;
    }
    return 0;
}

Intercept<int> Divide(Intercept<int> a, Intercept<int> b)
{
    int length = 2;
    Intercept<int> intercepts[length] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> Sum(0, 3);
    // Intercept<int> i(0, 2);
    Intercept<int> Flag = 0;
    if (a != 1)
    {
        for (state[1] = b; state[1] > 1; state[1]--)
        {
            if (a % state[1] == 0)
                state[0] += Divide(a / state[1], state[1]);
            Flag = 1;
        }
    }
    if (Flag == 0 || a == 1)
    {
        state[0] = 1;
    }
    return state[0];
}
