#include<iostream>
using namespace std;
//抽象类
class Father
{
public:
	//纯虚函数
	virtual void talking() = 0;
};
class Son :public Father
{
public:
	void talking()
	{
		cout << "子类的输出" << endl;
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