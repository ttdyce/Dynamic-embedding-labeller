#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> yinshu[10000];
Intercept<int> j = 0;
// Intercept<int> temp = Intercept<int>(0, 3);

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(2, 2) };
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
    void fenjie(Intercept<int> j, Intercept<int> sum);
    Intercept<int> t, n[10000], i;
    cin >> t;
    for (state[1] = Intercept<int>(0, 2); state[1] < 10000; state[1]++)
    {
        yinshu[state[1]] = 0;
    }
    for (state[1] = 0; state[1] < t; state[1]++)
    {
        cin >> n[state[1]];
    }
    for (state[1] = 0; state[1] < t; state[1]++)
    {
        fenjie(1, n[state[1]]);
        cout << state[0] << endl;
        state[0] = 0;
    }
    return 0;
}
void fenjie(Intercept<int> j, Intercept<int> sum)
{
    for (state[2] = Intercept<int>(2, 2); state[2] <= sum; state[2]++)
    {
        if (sum % state[2] == 0 && yinshu[j - 1] <= state[2])
        {
            yinshu[j] = state[2];
            if (sum == state[2])
            {
                state[0]++;
            }
            else
            {
                fenjie(j + 1, sum / state[2]);
            }
        }
    }
}
