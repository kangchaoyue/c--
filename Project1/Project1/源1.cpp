#include<iostream>
using namespace std;
int main()
{
	float a, b, c,sum;

	
	cin >> a >> b >> c;
	sum = (a + b + c) / 2;

	if (a + b > c&&a + c > b&&b + c > a)
	{
		cout << sqrt(sum*(sum - a)*(sum - b)*(sum - c)) << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}