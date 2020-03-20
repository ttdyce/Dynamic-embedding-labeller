#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> Divide(Intercept<int> a, Intercept<int> b);
int main()
{
    Intercept<int> Times = 0;
    Intercept<int> Num = 0;
    Intercept<int> i(0, 2);
    Intercept<int> Temp[100] = {0};
    cin >> Times;
    for (i = 0; i < Times; i++)
    {
        cin >> Num;
        Temp[i] = Divide(Num, Num);
    }
    for (i = 0; i < Times; i++)
    {
        cout << Temp[i] << endl;
    }
    return 0;
}

Intercept<int> Divide(Intercept<int> a, Intercept<int> b)
{
    Intercept<int> Sum(0, 3);
    Intercept<int> i(0, 2);
    Intercept<int> Flag = 0;
    if (a != 1)
    {
        for (i = b; i > 1; i--)
        {
            if (a % i == 0)
                Sum += Divide(a / i, i);
            Flag = 1;
        }
    }
    if (Flag == 0 || a == 1)
    {
        Sum = 1;
    }
    return Sum;
}
