#include<iostream>
using namespace std;
//��̬��̬����������
//�м̳й�ϵ  ������д�����е��麯��
//��̬��ʹ������
//�����ָ���������ָ������Ķ���
class Animal
{
public:
	virtual void speak()
	{
		cout << "����һ������" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "����һֻè" << endl;
	}
};
class Dog :public Animal
{
	void speak()
	{
		cout << "����һֻ��" << endl;
	}
};
//��Ϊ����Ǻ����ڱ����ʱ���ַ���Ѿ�ȷ���ˣ����������õ���Animal
//������Ҫ���л���ĺ�������д--�����ķ���ֵ���β��б�������
//����virtual�������黯  ���������ĵ�ַ�Ͳ����ڱ���׶�ȷ�� �ͳ��˶�̬�Ķ�̬

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