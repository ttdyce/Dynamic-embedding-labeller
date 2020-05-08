#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//????
Intercept<int> divide(Intercept<int> n, Intercept<int> i); //????   n???????i?????????
int main()
{
    Intercept<int> n = 0;     //?????
    Intercept<int> t = 0;     //????
    // Intercept<int> sum(0, 3); //???????

    Intercept<int> intercepts[3] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(2, 2)};
    StateIntercept state(intercepts, 3);

    cin >> t;
    for (state[1]; state[1] < t; state[1]++)
    {
        state[0] = 0;
        cin >> n;
        for (state[2]; state[2] <= n / 2; state[2]++) //???????????1*n???
        {
            state[0] = state[0] + divide(n, state[2]);
        }
        cout << state[0] + 1 << endl;
    }
    return 0;
}
Intercept<int> divide(Intercept<int> n, Intercept<int> i) //???????????????1???
{
    // Intercept<int> num(0, 3);
    Intercept<int> intercepts[2] = {Intercept<int>(0, 3), Intercept<int>(2, 2)};
    StateIntercept state(intercepts, 2);
    if (n % i == 0)
    {
        if (n == i) //?????????????????1
        {
            return 1;
        }
        for (state[1]; state[1] <= i; state[1]++)
        {
            state[0] = state[0] + divide(n / i, state[1]); //??
        }
        return state[0];
    }

    else
    {
        return 0;
    }
}
