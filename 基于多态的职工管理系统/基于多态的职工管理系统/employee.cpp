#include"employee.h"
using namespace std;
 Employee::Employee(int id, string name, int dId)
{
	 this->m_DeptId = dId;
	 this->m_Id = id;
	 this->m_Name = name;
}
 //��ʾ���˵���Ϣ
  void Employee::showInfo()
 {
	  cout << "ְ���ı��" << this->m_Id
		  << "\tְ��������" << this->m_Name
		  << "\t��λ:" << this->getDeptName()
		  << endl;
 }
  string Employee::getDeptName()
 {
	  return string("Ա��");
 }
