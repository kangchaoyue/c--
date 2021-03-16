#include"employee.h"
using namespace std;
 Employee::Employee(int id, string name, int dId)
{
	 this->m_DeptId = dId;
	 this->m_Id = id;
	 this->m_Name = name;
}
 //显示个人的信息
  void Employee::showInfo()
 {
	  cout << "职工的编号" << this->m_Id
		  << "\t职工的名字" << this->m_Name
		  << "\t岗位:" << this->getDeptName()
		  << endl;
 }
  string Employee::getDeptName()
 {
	  return string("员工");
 }
