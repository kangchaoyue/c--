#include<fstream>
#include<iostream>
using namespace std;
class Person
{
public:
	char name[20];
	int age;
};
int main3()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);//���ö����Ƶķ�ʽ��д   
	Person p = {"lihao",18};
	ofs.write((const char*)&p, sizeof(Person));//��һ�������� ����ָ�����͵�  �ڶ��������Ǵ�������ݵĴ�С
	return 0;
}