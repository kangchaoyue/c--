#include<iostream>
#include<string>
using namespace std;
class Print
{
public:
	void operator()(string test)
	{
		cout << test << endl;
	}
	
};
void test13()
{
	Print()("kcy");
}
int main()
{
	test13();
	return 0;
}