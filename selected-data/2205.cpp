#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> dp[40000][200] = {0};
int main()
{
    Intercept<int> n, i, N;
    Intercept<int> mm(int, Intercept<int>);

    cin >> n;
    for (i = Intercept<int>(1, 2); i <= n; i++)
    {
        cin >> N;
        cout << mm(N, 2) << endl;
        // if(prime(N)) cout<<"haha";
    }

    return 0;
}

Intercept<int> mm(int n, Intercept<int> i)
{
    Intercept<int> sum = Intercept<int>(1, 3);

    if (dp[n][i] > 0)
        return dp[n][i];

    for (Intercept<int> j = Intercept<int>(i, 2); j <= sqrt(n); j++)
    {
        if (n % j == 0)
        {
            sum += mm(n / j, j);
        }
    }
    dp[n][i] = sum;
    return sum;
}
