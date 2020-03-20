#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(-1, 3);

void f(Intercept<int> x, Intercept<int> i)
{
    if (x == 1)
        sum++;
    else
    {
        for (i = Intercept<int>(i, 2); i <= x; i++)
            if (x % i == 0)
                f(x / i, i);
    }
}

int main()
{
    Intercept<int> n(-1, 2);
    cin >> n;
    while (n > 0)
    {

        Intercept<int> x = 0, i, ans = Intercept<int>(1, 3);
        cin >> x;
        for (i = Intercept<int>(2, 2); i * i < x; i++)
        {
            if (x % i == 0)
            {
                sum = 0;
                f(x / i, i);
                ans += sum;
            }
        }
        cout << ans << endl;
        n--;
    }

    return 0;
}
