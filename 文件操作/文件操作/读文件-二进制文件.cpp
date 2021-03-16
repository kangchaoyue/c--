#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Person
{
public:
	char name[20];
	int age;
};
int main()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败";
		return 0;
	}
	Person p;
	ifs.read((char *)&p, sizeof(Person));
	cout << "名字 :" << p.name << "年龄" << p.age << endl;
	ifs.close();
	return 1;
}
