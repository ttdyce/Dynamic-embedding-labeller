#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 3);
void recur(Intercept<int> N, Intercept<int> i)
{
    i = Intercept<int>(i, 2);
    if (N == 1)
        sum++;
    while (i <= N)
    {
        if (N % i == 0)
            recur(N / i, i);
        i++;
    }
    return;
}
int main()
{
    Intercept<int> t = 0;
    cin >> t;
    for (Intercept<int> k(0, 2); k < t; k++)
    {
        Intercept<int> n = 0;
        cin >> n;
        Intercept<int> i = 2, res(1, 3);
        for (Intercept<int> i(2, 2); i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                sum = 0;
                recur(n / i, i);
                res += sum;
            }
        }
        cout << res << endl;
    }
    return 0;
}
