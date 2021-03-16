#include"manager.h"
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manager::showInfo()
{
	cout << "职工的编号" << this->m_Id
		<< "\t职工的名字" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< endl;
}
string Manager::getDeptName()
{
	return string("经理");
}