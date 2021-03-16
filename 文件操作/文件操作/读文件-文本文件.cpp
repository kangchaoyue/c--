#include<fstream>
#include<iostream>
#include<string>  
using namespace std;
int main2()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())//ifs.is_open()返回的是bool类型  判断文件是否打开成功
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
	//读取文件数据
	//1利用右移运算符
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	//每次读取到一个空格或者一个换行  就输出一次
	//	cout << buf << endl;
	//}
	//第二种：通过getline
	//while (ifs.getline(buf, sizeof(buf)))//第一个参数是字符指针，第二个参数是规定我们最多要读取多少个字符
	//{
	//	cout << buf << endl;
	//}
	//第三种：通过字符串
	string buf;
	//while (getline(ifs, buf))//第一个 参数是输入流对象  第二个参数是一个字符串
	//{
	//	cout << buf << endl;
	//}
	//第四种   通过字符来读取 一次读取一个
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c ;
	}
	ifs.close();
	system("pause");
	return 0;
}