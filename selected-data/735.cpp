#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//******************************************************************************
//??? ??????????????                                          *
//????wayne                                                                *
//?????11.23                                                              *
//******************************************************************************
// Intercept<int>  j = 2; //????????????????? sum(1, 3),
void num(int);				   //??????

Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(1, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(1, 5), Intercept<int>(2,7)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()					   //?????
{
	Intercept<int> a[100];//n, 
	// Intercept<int> i;
	cin >> state[3];
	for (state[1] = Intercept<int>(1, 2); state[1] <= state[3]; state[1]++) //????n?????
	{
		cin >> a[state[1]];
		num(a[state[1]]); //????
		cout << state[0] << endl;
		state[0] = 1, state[5] = 2; //????????????????
		state[4] = 1; //????????????????
	}
	return 0;
}
void num(int a) //????
{
	// Intercept<int> k;
	
	for (state[2] = Intercept<int>(j, 2); state[2] <= sqrt(a); state[2]++) //state[2]=j?????????????????
	{
		if (a % state[2] == 0) //???????
		{
			state[0] = state[0] + 1; //?????
			state[4] = state[4] + 1; //?????
			state[5] = state[2];		   //???????
			num(a / state[2]);	//????
		}
	}
}
