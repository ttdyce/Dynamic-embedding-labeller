#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> yinshu[10000];
Intercept<int> j = 0;
Intercept<int> temp = Intercept<int>(0, 3);
int main()
{
    void fenjie(Intercept<int> j, Intercept<int> sum);
    Intercept<int> t, n[10000], i;
    cin >> t;
    for (i = Intercept<int>(0, 2); i < 10000; i++)
    {
        yinshu[i] = 0;
    }
    for (i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (i = 0; i < t; i++)
    {
        fenjie(1, n[i]);
        cout << temp << endl;
        temp = 0;
    }
    return 0;
}
void fenjie(Intercept<int> j, Intercept<int> sum)
{
    for (Intercept<int> i = Intercept<int>(2, 2); i <= sum; i++)
    {
        if (sum % i == 0 && yinshu[j - 1] <= i)
        {
            yinshu[j] = i;
            if (sum == i)
            {
                temp++;
            }
            else
            {
                fenjie(j + 1, sum / i);
            }
        }
    }
}
