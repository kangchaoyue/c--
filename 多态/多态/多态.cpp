#include<iostream>
using namespace std;
//动态多态的满足条件
//有继承关系  子类重写父类中的虚函数
//多态的使用条件
//父类的指针或者引用指向子类的对象
class Animal
{
public:
	virtual void speak()
	{
		cout << "我是一个动物" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "我是一只猫" << endl;
	}
};
class Dog :public Animal
{
	void speak()
	{
		cout << "我是一只狗" << endl;
	}
};
//因为这个是函数在编译的时候地址就已经确定了，所以最后调用的是Animal
//我们需要进行基类的函数的重写--函数的返回值，形参列表，都不变
//利用virtual将函数虚化  这样函数的地址就不会在编译阶段确定 就成了动态的多态

void WhoSpeak(Animal &animal)
{
	animal.speak();
}
int main1()
{
	Cat cat;
	WhoSpeak(cat);
	Dog dog;
	WhoSpeak(dog);
	return 0;
}