#pragma once
#include<iostream>
#include<string>
using namespace std;


//职工的抽象基类  为后面子类的做继承 
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//显示岗位名称
	virtual string getDeptName() = 0;

	int m_Id;//职工编号
	string m_Name;//职工的姓名
	int m_DeptId;//职工所在部门名称编号
};


