#include"manager.h"
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manager::showInfo()
{
	cout << "ְ���ı��" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< endl;
}
string Manager::getDeptName()
{
	return string("����");
}