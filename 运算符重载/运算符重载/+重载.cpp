#include<iostream>
using namespace std;
class Person
{
public:
	int m_a;
	int m_b;
	Person operator+(Person &p)
	{
		Person temp;
		temp.m_a = this->m_a + p.m_a;
		temp.m_b = this->m_b + p.m_b;
		return temp;
	}
};
int main11()
{
	Person a, b, c;
	a.m_a = 10;
	a.m_b = 10;
	b.m_b = 10;
	b.m_a = 10;
	c = a + b;
	cout << c.m_a << "   " << c.m_b << endl;
	return 0;
}