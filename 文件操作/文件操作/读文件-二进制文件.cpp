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
		cout << "�ļ���ʧ��";
		return 0;
	}
	Person p;
	ifs.read((char *)&p, sizeof(Person));
	cout << "���� :" << p.name << "����" << p.age << endl;
	ifs.close();
	return 1;
}
