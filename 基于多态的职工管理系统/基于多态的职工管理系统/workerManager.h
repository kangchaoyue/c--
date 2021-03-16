
#pragma once//防止头文件重复包含
#include<iostream>
#include"worker.h"
#include"manager.h"
#include"boss.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单

	void Show_Menu();
	void exitSystem();//退出系统的成员函数
  
	//记录职工的人数
	int m_EmpNum = 0;

	//记录职工数组的指针
	Worker ** m_EmpArray;
	//添加职工的函数
	void Add_Emp();
	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示职工的信息
	void Show_Emp();
	//删除职工
	void Del_emp();
	//判断职工是否存在
	int IsExist_emp(int id); 
	//修改职工的信息
	void Mod_emp();
	//查找员工
	void Find_Emp();
	//判断当前的传入参数的Id是否已经存在
	
	
	bool Exist_Id(int id);
	//对员工进行排序
	void Sort_Emp();
	//对文件进行清空
	void Clean_File();

	//析构函数

	
	~WorkerManager();




};