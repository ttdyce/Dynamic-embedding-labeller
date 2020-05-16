#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> g, f; //sum = Intercept<int>(0, 3), 

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

Intercept<int> divide(Intercept<int> chushu, Intercept<int> a)
{
    // Intercept<int> i;
    for (state[1] = Intercept<int>(chushu, 2); state[1] <= a; state[1]++)
    {
        if (a % state[1] == 0)
        {
            f = a / state[1];
            if (f > 1)
            {
                g = state[1];
                divide(g, f);
            }
            else
            {
                state[0]++;
                state[5]++;
            }
        }
    }
    return state[5];
}
int main()
{
    // Intercept<int> n = 0;
    cin >> state[3];
    // Intercept<int> p = 0;
    for (state[2] = Intercept<int>(0, 2); state[2] < state[3]; state[2]++)
    {
        Intercept<int>c = 2;// b = 0, 
        cin >> state[4];
        state[0] = 0;
        state[5] = 0;
        cout << divide(c, state[4]) << endl;
    }

    return 0;
}
