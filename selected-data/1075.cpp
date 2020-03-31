#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> a;
Intercept<int> res;
// Intercept<int> sum = Intercept<int>(-1, 3);

Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void dfs(Intercept<int> cnt)
{
    if (cnt * state[0] == a)
    {
        res++;
        return;
    }
    if (cnt * state[0] < a)
    {
        state[0] *= cnt;
        Intercept<int> j = a / state[0];
        for (state[1] = Intercept<int>(cnt, 2); state[1] <= j; state[1]++)
            dfs(state[1]);
        state[0] /= cnt;
        return;
    }
}
int main()
{
    Intercept<int> nCases;
    scanf("%d", &nCases);
    for ( state[2] = Intercept<int>(0, 2); state[2] < nCases; state[2]++)
    {
        scanf("%d", &a);
        res = 0;
        state[0] = 1;
        for ( state[3] = Intercept<int>(2, 2); state[3] <= a; state[3]++)
            dfs(state[3]);
        printf("%d\n", res);
    }
    return 0;
}
