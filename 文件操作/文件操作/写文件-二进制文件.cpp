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
	ofs.open("person.txt", ios::out | ios::binary);//利用二进制的方式来写   
	Person p = {"lihao",18};
	ofs.write((const char*)&p, sizeof(Person));//第一个参数是 常量指针类型的  第二个参数是传入的数据的大小
	return 0;
}