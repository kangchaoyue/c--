#include<iostream>
using namespace std;
//������
class Father
{
public:
	//���麯��
	virtual void talking() = 0;
};
class Son :public Father
{
public:
	void talking()
	{
		cout << "��������" << endl;
	}
};
void test3()
{
	Son().talking();
}
int main()
{
	test3();
	return 0;
}