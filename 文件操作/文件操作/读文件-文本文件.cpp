#include<fstream>
#include<iostream>
#include<string>  
using namespace std;
int main2()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open())//ifs.is_open()���ص���bool����  �ж��ļ��Ƿ�򿪳ɹ�
	{
		cout << "�ļ���ʧ��" << endl;
		return 0;
	}
	//��ȡ�ļ�����
	//1�������������
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	//ÿ�ζ�ȡ��һ���ո����һ������  �����һ��
	//	cout << buf << endl;
	//}
	//�ڶ��֣�ͨ��getline
	//while (ifs.getline(buf, sizeof(buf)))//��һ���������ַ�ָ�룬�ڶ��������ǹ涨�������Ҫ��ȡ���ٸ��ַ�
	//{
	//	cout << buf << endl;
	//}
	//�����֣�ͨ���ַ���
	string buf;
	//while (getline(ifs, buf))//��һ�� ����������������  �ڶ���������һ���ַ���
	//{
	//	cout << buf << endl;
	//}
	//������   ͨ���ַ�����ȡ һ�ζ�ȡһ��
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c ;
	}
	ifs.close();
	system("pause");
	return 0;
}