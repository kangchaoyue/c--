
#include <iostream>
using namespace std;
//���ύ�Ĵ��뽫Ƕ�뵽����
class Rectangle
{
public:
	float a, b;
	void set(float m, float n)
	{
		a = m;
		b = n;
	}
	float getArea()
	{
		return(a*b);
	}
	float getPerimeter()

	{
		return(2 * (a + b));
	}
};
int main4()
{
	double m, n;
	cin >> m;
	cin >> n;
	Rectangle a;
	a.set(m, n);
	cout << a.getArea() << endl;
	cout << a.getPerimeter() << endl;
	return 0;
}