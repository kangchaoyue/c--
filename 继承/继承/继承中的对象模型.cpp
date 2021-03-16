#include<iostream>
using namespace std;
class Base
{
public:
	int a;
protected:
	int b;
private:
	int c;
};
class Son :public Base
{
public:
	int d;
};
int main1()
{
	Son p;
	cout << sizeof(p) << endl;
	return 0;
}