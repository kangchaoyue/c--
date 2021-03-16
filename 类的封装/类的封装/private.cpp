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
	string u_name;//可读可写
	int age  = 10;//可读
};
int main()
{
	cl cc;
	cc.set_name("kcy");
	cout << "名字为：" << cc.get_name() << "年龄为：" << cc.get_age() << endl;
}