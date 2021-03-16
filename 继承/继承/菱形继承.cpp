#include<iostream>
using namespace std;
class Base0
{
public:

	int m_A;
};
class Base1 : public Base0
{


};
class Base2 : public Base0
{

};
class Son :public Base1, public Base2
{

};
void test()
{
	Son s;
	s.Base2::m_A = 100;
	s.Base1::m_A = 200;
	cout << "Base1 µÄ m_A" << s.Base1::m_A << endl;
	cout << "Base2 µÄ m_A" << s.Base2::m_A << endl;
	//cout << "Son µÄ m_A" << s.m_A << endl;
}
int main()
{
	test();
	return 0;
}