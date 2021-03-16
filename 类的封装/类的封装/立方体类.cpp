#include"iostream"
using namespace std;
class cube {
public:

	
	//设置长宽高
	void set_LWH(int length1, int width1, int height1)
	{
		length = length1;
		width = width1;
		height = height1;
	}
	int S_TJ(void)
	{
		return (length*width*height);
	}
private:
	int length;
	int width;
	int height;

 };
int main()
{
	cube cc;
	cc.set_LWH(3, 4, 5);
	cout << "立方体的体积为" << cc.S_area() << endl;
}