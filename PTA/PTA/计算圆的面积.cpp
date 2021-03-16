#include<iostream>
using namespace std;
class yuan
{
public:
	float r;
	void out_area()
	{
		cout << 3.1415926*r*r << endl;
	}
};
int main1()
{
	yuan p;
	cin >> p.r;
	p.out_area();
	return 0;
}