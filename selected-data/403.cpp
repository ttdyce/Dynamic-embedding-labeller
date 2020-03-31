#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divmet(Intercept<int> n, Intercept<int> i);
int main()
{
    int length = 3;
    Intercept<int> intercepts[length] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(2, 2)};
    StateIntercept state(intercepts, length);

    Intercept<int> n = 0; //?????
    Intercept<int> t = 0; //????
    // Intercept<int> sum(0, 3);   //???????
    cin >> t;
    for (state[1]; state[1] < t; state[1]++)
    {
        state[0] = 0;
        cin >> n;
        for (state[2]; state[2] <= n; state[2]++)
        {
            state[0] = state[0] + divmet(n, state[2]);
        }
        cout << state[0] << endl;
    }
    return 0;
}
Intercept<int> divmet(Intercept<int> n, Intercept<int> i)
{
    int length = 1;
    Intercept<int> intercepts[length] = {Intercept<int>(2, 2)};
    StateIntercept state(intercepts, length);

    Intercept<int> num = 0;
    if (n % i == 0)
    {
        if (n == i)
        {
            return 1;
        }
        for (state[0]; state[0] <= i; state[0]++)
        {
            num = num + divmet(n / i, state[0]); //??
        }
        return num;
    }

    else
    {
        return 0;
    }
}
