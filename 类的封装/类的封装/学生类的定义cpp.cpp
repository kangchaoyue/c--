#include"iostream"
#include"string"
using namespace std;
class Student
{
public:

	string name;
	int num;
	void print() {
		cout << name << endl;
		cout << num << endl;
	}
	void input_name(string name1)
	{
		name = name1;
	}
	void input_num(int num1)
	{
		num = num1;
	}
};
int main()
{
	Student ming;
	ming.input_name("kcy");
	ming.input_num(1);
	ming.print();
	system("pause");

	
}