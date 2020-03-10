#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> a;
Intercept<int> res;
Intercept<int> sum = Intercept<int>(-1, 3);
void dfs(Intercept<int> cnt)
{
    if (cnt * sum == a)
    {
        res++;
        return;
    }
    if (cnt * sum < a)
    {
        sum *= cnt;
        Intercept<int> j = a / sum;
        for (Intercept<int> i = Intercept<int>(cnt, 2); i <= j; i++)
            dfs(i);
        sum /= cnt;
        return;
    }
}
int main()
{
    Intercept<int> nCases;
    scanf("%d", &nCases);
    for (Intercept<int> i(0, 2); i < nCases; i++)
    {
        scanf("%d", &a);
        res = 0;
        sum = 1;
        for (Intercept<int> i(2, 2); i <= a; i++)
            dfs(i);
        printf("%d\n", res);
    }
    return 0;
}
