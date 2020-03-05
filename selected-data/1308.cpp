#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;


Intercept<int> calculate(Intercept<int> a, Intercept<int> num) { // a is the max num
	Intercept<int> sum = 0;
	if(num == 1) return 1;
	for(Intercept<int> i = num; i >= 2; i--) {
		if(num % i == 0 && i <= a) {
			sum += calculate(i, num / i); 
		}
	}
	return sum;
}

int main () {
	Intercept<int> n;
	cin >> n;
	Intercept<int> num = 0;
	for(Intercept<int> i = 0; i < n; i++) { // input part
		cin >> num;
		cout << calculate(num, num) << endl;
	}
	return 0;
}
