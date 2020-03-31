#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//n???????i?????????
Intercept<int> divi(Intercept<int> n, Intercept<int> i)
{
	int length = 2;
	Intercept<int> intercepts[length] = {Intercept<int>(0, 3), Intercept<int>(2, 2)};
	StateIntercept state(intercepts, length);

    // Intercept<int> num = Intercept<int>(0, 3);
    if (n % i == 0)
    {
        if (n == i) //?????????????????1
        {
            return 1;
        }
        for (state[1]; state[1] <= i; state[1]++)
        {
            state[0] = state[0] + divi(n / i, state[1]); //??
        }
        return state[0];
    }

    else
    {
        return 0;
    }
}

int main()
{
	int length = 3;
	Intercept<int> intercepts[length] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, length);

    Intercept<int> n = 0; //?????
    Intercept<int> t = 0; //????
    // Intercept<int> sum(-1, 3);   //?????
    cin >> t;
    for (state[1]; state[1] < t; state[1]++)
    {
        state[0] = 0;
        cin >> n;
        for (state[2]; state[2] <= n / 2; state[2]++) //?????????1*n???
        {
            state[0] = state[0] + divi(n, state[2]);
        }
        cout << state[0] + 1 << endl;
    }
    return 0;
}
