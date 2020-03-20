#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum = Intercept<int>(0, 3), g, f;
Intercept<int> divide(Intercept<int> chushu, Intercept<int> a)
{
    Intercept<int> i;
    for (i = Intercept<int>(chushu, 2); i <= a; i++)
    {
        if (a % i == 0)
        {
            f = a / i;
            if (f > 1)
            {
                g = i;
                divide(g, f);
            }
            else
            {
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    Intercept<int> n = 0;
    cin >> n;
    Intercept<int> p = 0;
    for (p = Intercept<int>(0, 2); p < n; p++)
    {
        Intercept<int> b = 0, c = 2;
        cin >> b;
        sum = 0;
        cout << divide(c, b) << endl;
    }

    return 0;
}
