#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

// Intercept<int> sum(0, 3); //?????????????
void count(Intercept<int> N, Intercept<int> i)
{
    state[1] = Intercept<int>(i, 2);

    if (N == 1)
        state[0]++; //??N??????i?????N???1????????????????state[0]??1
    while (state[1] <= N)
    {
        if (N % state[1] == 0)
            count(N / state[1], state[1]);
        state[1]++; //N??????????????i?
    }
    return;
}
int main()
{
    // Intercept<int> T(0, 2); //??????
    
    cin >> state[2];
    while (state[2]--)
    {
        // Intercept<int> N = 0; //?????
        cin >> state[5];
        // Intercept<int> i(2, 2), total(1, 3); //???????2???a=a????????total?????1
        state[3] = Intercept<int>(2, 2);
        state[4] = Intercept<int>(1, 3);
        state[6] = Intercept<int>(1, 3);
        while (state[3] <= state[5] / 2)
        {
            if (state[5] % state[3] == 0)
            {
                state[0] = 0;
                count(state[5] / state[3], state[3]);
                state[4] += state[0];
                state[6] += state[0];
            } //??state[5]??????????????????????
            state[3]++;
        }
        cout << state[4] << endl;
    }
    return 0;
}
