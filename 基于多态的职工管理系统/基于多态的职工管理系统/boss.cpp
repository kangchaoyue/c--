#include"boss.h"
using namespace std;
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Boss::showInfo()
{
	cout << "ְ���ı��" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< endl;
}
string Boss::getDeptName()
{
	return string("�ϰ�");
}