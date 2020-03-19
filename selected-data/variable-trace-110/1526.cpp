#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 3);
Intercept<int> f(Intercept<int> a, Intercept<int> b)
{
    for (Intercept<int> i(a, 2); i > 1; i--)
    {
        if (a % i != 0)
        {
            continue;
        }
        else
        {
            if (i > b)
            {
                continue;
            }
            else
            {
                Intercept<int> q;
                q = a / i;
                if (q == 1)
                {
                    sum++;
                }
                else
                {
                    f(q, i);
                }
            }
        }
    }
    return sum;
}

int main()
{
    Intercept<int> n;
    cin >> n;
    for (Intercept<int> i(1, 2); i <= n; i++)
    {
        Intercept<int> num;
        cin >> num;
        Intercept<int> c;
        c = f(num, num);
        cout << c << endl;
        sum = 0;
    }
    return 0;
}
