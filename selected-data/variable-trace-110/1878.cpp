#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 2);                       //???????????
void fact(Intercept<int> a, Intercept<int> i) //?????;??????????a?????i?????
{
    i = Intercept<int>(i, 2);

    if (a == 1)
        sum++;     //???????N=1????????N????????1
    while (i <= a) //????i???N
    {
        if (a % i == 0)
            fact(a / i, i); //??N??i?????????????N/i??
        i++;                //??N???i???i?1
    }
}
int main() //???
{
    Intercept<int> n(-1, 2); //?????????
    cin >> n;         //??????
    while (n--)       //??
    {
        Intercept<int> a;          //??????????
        cin >> a;                  //????
        Intercept<int> i(2, 2);      //???????2?
        Intercept<int> result(1, 3); //????????a??????
        while (i <= a / 2)         //??i???a???
        {
            if (a % i == 0) //??i?a???
            {
                sum = 0;        //sum??
                fact(a / i, i); //????????/i
                result += sum;  //????????i????
            }
            i++; //i?1
        }
        cout << result << endl; //??????
    }
    return 0;
}
