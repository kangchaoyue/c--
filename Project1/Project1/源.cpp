#include<iostream>
using namespace std;

/* 请在这里填写答案 */
float myMax(float a = -9999, float b = -9999, float c = -9999)
{
	int max;
	if (a > b && a > c)
		return a;
	else if (b > a&& b > c)
		return b;
	else if (c > a&&c > b)
		return c;
}
int main1() {
	cout << myMax(3, 4) << endl;
	cout << myMax(3, 4, 5) << endl;
	cout << myMax(4.3, 3.4) << endl;
	return 0;
}
