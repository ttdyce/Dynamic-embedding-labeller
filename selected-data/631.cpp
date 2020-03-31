#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void decprime(Intercept<int> begain, Intercept<int> a);
// Intercept<int> sum = Intercept<int>(1, 3);
Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts)/sizeof(intercepts[0]));

int main()
{
	Intercept<int> n, a;
	// Intercept<int> k;
	cin >> n;
	for (state[1]; state[1] < n; state[1]++)
	{
		cin >> a;
		decprime(2, a);
		cout << state[0] << endl;
		state[0] = 1;
	}
	return 0;
}
void decprime(Intercept<int> begain, Intercept<int> a)
{
	// Intercept<int> i;
	//Intercept<int> u=int(sqrt(double(a)));
	//Intercept<int> m[10000]={};

	//if(a==2||a==3||a==5)return 1;
	//else{
	state[2] = Intercept<int>(begain, 2);
	for (state[2]; state[2] <= a; state[2]++)
	{
		if (a % state[2] == 0 && state[2] <= a / state[2])
		{
			state[0]++;
			decprime(state[2], a / state[2]);
		}
		if (state[2] > a / state[2])
			break;
		//m[i]=decprime(a/i);
		//else m[i]=0;
		//sum+=m[i];
		//}
		//return sum+1;
	}
}
