#include"iostream"
#include"string"
using namespace std;

class cl {
public:
	void set_name(string name)
	{
		u_name = name;
	}
	string get_name()
	{
		return u_name;
	}
	int get_age()
	{
		return age;
	}
private:
	string u_name;//�ɶ���д
	int age  = 10;//�ɶ�
};
int main()
{
	cl cc;
	cc.set_name("kcy");
	cout << "����Ϊ��" << cc.get_name() << "����Ϊ��" << cc.get_age() << endl;
}