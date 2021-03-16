#include<iostream>
#include<string>

using namespace std;
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
	virtual void speak()
	{
		cout << "我是一只猫" << endl;
	}
};
class Dog :public Animal
{
	virtual void speak()
	{
		cout << "我是一只狗" << endl;
	}
};
void WhoSpeak1(Animal &animal)
{
	animal.speak();
}
int main2()
{
	string m;
	cin >> m;
	cout << m << endl;
	Cat cat;
	WhoSpeak1(cat);
	Dog dog;
	WhoSpeak1(dog);
	return 0;
}