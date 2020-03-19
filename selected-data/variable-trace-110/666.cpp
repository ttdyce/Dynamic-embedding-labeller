#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(-1, 3);
Intercept<int> yin(Intercept<int> c, Intercept<int> g) //?????
{
    Intercept<int> j, k, f, e;
    for (j = Intercept<int>(g, 2); j <= c; j++) //??
    {
        if (c % j == 0)
        {
            e = c / j;
            if (e > 1)
            {
                f = j;
                yin(e, f);
            }
            else
                sum++; //?????????
        }
    }
    return sum; //??
}
int main()
{
    Intercept<int> n, a[1000], b[1000], i, d;
    cin >> n;
    for (i = Intercept<int>(0, 2); i < n; i++)
        cin >> a[i]; //??
    for (i = 0; i < n; i++)
    {
        d = 2;
        sum = 0;
        b[i] = yin(a[i], d);
    }
    for (i = 0; i < n; i++)
        cout << b[i] << endl; //??
    return 0;
}
