#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "���캯��" << endl;
	}
	~Person()
	{
		cout << "��������" << endl;
	}
};
void test0()
{
	Person p;
}
int main()
{
	test0();
}