#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> dp[40000][200] = {0};
int main()
{
    Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    Intercept<int> n, N; //i, 
    Intercept<int> mm(int, Intercept<int>);

    cin >> n;
    for (state[0] = Intercept<int>(1, 2); state[0] <= n; state[0]++)
    {
        cin >> N;
        cout << mm(N, 2) << endl;
        // if(prime(N)) cout<<"haha";
    }

    return 0;
}

Intercept<int> mm(int n, Intercept<int> i)
{
    Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

    // Intercept<int> sum = Intercept<int>(1, 3);

    if (dp[n][i] > 0)
        return dp[n][i];

    for (state[1] = Intercept<int>(i, 2); state[1] <= sqrt(n); state[1]++)
    {
        if (n % state[1] == 0)
        {
            state[0] += mm(n / state[1], state[1]);
        }
    }
    dp[n][i] = state[0];
    return state[0];
}
