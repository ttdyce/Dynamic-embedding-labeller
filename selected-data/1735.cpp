#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void f(Intercept<int> n, Intercept<int> i)
{
    if (n == 1)
        state[0]++;
    state[1] = i;
    while (state[1] <= n)
    {
        if (n % state[1] == 0)
            f(n / state[1], state[1]);
        state[1]++;
    }
    return;
}
int main()
{

    // Intercept<int> t(0, 2);
    cin >> state[2];
    while (state[2]--)
    {
        Intercept<int> n = 0;
        cin >> n;
        Intercept<int> i = 2, result = 1;

        for (state[3] = Intercept<int>(2, 2); state[3] <= n / 2; state[3]++)
        {
            if (n % state[3] == 0)
            {
                state[0] = 0;
                f(n / state[3], state[3]);
                result = result + state[0];
            }
        }
        cout << result << endl;
    }
    return 0;
}
