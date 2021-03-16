#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		m_age = age;
		m_name = name;
	}
	bool operator!=(Person b)
	{
		if (this->m_age == b.m_age && this->m_name == b.m_name)
			return false;
		else
			return true;
	}
	bool operator==(Person b)
	{
		if (this->m_age == b.m_age && this->m_name == b.m_name)
			return true;
		else
			return false;
	}
	string m_name;
	int m_age;
};

void test()
{
	Person p("kcy", 18);
	Person p2("zjq", 18);
	if (p == p2)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不想等" << endl;
	}
}
int main16()
{
	test();
	return 0;
}