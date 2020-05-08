#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> g, f; //sum = Intercept<int>(0, 3), 

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
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
            }
        }
    }
    return state[0];
}
int main()
{
    Intercept<int> n = 0;
    cin >> n;
    // Intercept<int> p = 0;
    for (state[2] = Intercept<int>(0, 2); state[2] < n; state[2]++)
    {
        Intercept<int> b = 0, c = 2;
        cin >> b;
        state[0] = 0;
        cout << divide(c, b) << endl;
    }

    return 0;
}
