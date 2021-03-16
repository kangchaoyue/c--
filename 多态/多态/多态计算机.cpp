#include<iostream>
using namespace std;
class Calculate
{
public:
	int num1;
	int num2;
	virtual int Get_result()
	{
		return 0;
	}
};
class AddCalculate:public Calculate
{
	int Get_result()
	{
		return num1 + num2;
	}
};
void test()
{
	
	Calculate *s = new AddCalculate;
	s->num1 = 100;
	s->num2 = 100;
	cout << s->num1 << "+" << s->num2 << "=" << s->Get_result() << endl;
}
int main3()
{
	test();
	return 0;
}