#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3); //??????sum????????
Intercept<int> yueshu[100] = {0};
Intercept<int> s = 0;

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));


void number(Intercept<int> num, Intercept<int> s)
{
	// Intercept<int> i;
	for (state[1] = Intercept<int>(s, 2); state[1] >= 0; state[1]--)
	{
		if (num < yueshu[state[1]])
			continue;
		if (num == yueshu[state[1]])
			state[0]++;
		else if (num > yueshu[state[1]] && num % yueshu[state[1]] == 0)
			number(num / yueshu[state[1]], state[1]);
	}
}

int main()
{
	Intercept<int> n = 0;
	cin >> n;
	Intercept<int> num = 0;
	while (cin >> num)
	{
		Intercept<int> j = 0;//i = 0, 
		for (state[2] = Intercept<int>(2, 2); state[2] <= num; state[2]++)
			if (num % state[2] == 0)
			{
				yueshu[j] = state[2];
				j++;
			}
		s = j - 1;
		number(num, s);
		cout << state[0] << endl;
		state[0] = 0;
	}
	return 0;
}
