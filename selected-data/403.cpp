#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divmet(Intercept<int> n, Intercept<int> i);
int main()
{
    Intercept<int> n = 0; //?????
    Intercept<int> t = 0; //????
    Intercept<int> sum(0, 3);   //???????
    cin >> t;
    for (Intercept<int> i(0,2); i < t; i++)
    {
        sum = 0;
        cin >> n;
        for (Intercept<int> j = (2, 2); j <= n; j++)
        {
            sum = sum + divmet(n, j);
        }
        cout << sum << endl;
    }
    return 0;
}
Intercept<int> divmet(Intercept<int> n, Intercept<int> i)
{
    Intercept<int> num = 0;
    if (n % i == 0)
    {
        if (n == i)
        {
            return 1;
        }
        for (Intercept<int> j(2, 2); j <= i; j++)
        {
            num = num + divmet(n / i, j); //??
        }
        return num;
    }

    else
    {
        return 0;
    }
}
