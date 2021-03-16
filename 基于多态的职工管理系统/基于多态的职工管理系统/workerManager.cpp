#include"workerManager.h"
#include<iostream>
using namespace std;
WorkerManager::WorkerManager()
{
	//文件不存在 
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		/*cout << "文件不存在" << endl;*/
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在没数据
	char ch;
	ifs >> ch; 
	if (ifs.eof())
	{
		//文件为空
		/*cout << "文件不存在" << endl;*/
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		return;

	}
	//文件存在，并且有内容
	int num = this->get_EmpNum();
	this->m_EmpNum = num; 
	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();
	this->m_FileIsEmpty = false;
}
void  WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker *worker = NULL;
		if (dId == 1)//职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//老板
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index++] = worker;
	}
	ifs.close();

}
//展示菜单
void WorkerManager::Show_Menu()
{
	cout << "\n\n\t\t\t\t欢迎使用职工管理系统" << endl;
	cout << "\t\t\t\t0.退出管理系统" << endl;
	cout << "\t\t\t\t1.增加职工的信息" << endl;
	cout << "\t\t\t\t2.显示职工的信息" << endl;
	cout << "\t\t\t\t3.删除离职职工的信息" << endl;
	cout << "\t\t\t\t4.修改职工信息" << endl;
	cout << "\t\t\t\t5.查找职工信息" << endl;
	cout << "\t\t\t\t6.按照编号排序" << endl;
	cout << "\t\t\t\t7.清空所有的文档\n\n" << endl;
}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
	}
	this->m_EmpNum = 0;
	delete[] this->m_EmpArray;
	this->m_EmpArray = NULL;
	this->m_FileIsEmpty = true;
}
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); 
}
void WorkerManager::Add_Emp()
{
	cout << "请输入添加的职工的数量" << endl;
	int addNum = 0;
	cin >> addNum;
	
	
	if (addNum > 0)
	{
		//计算添加的新的空间的大小  重新申请一个空间
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker*[newSize];
		//如果原来有数据  需要先把原来的先添加进去
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新的数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个员工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名：" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "个员工的岗位" << endl;
			cout << "1.普通的职工" << endl;
			cout << "2.一般的经理" << endl;
			cout << "3.优秀的老板" << endl;
			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1:worker = new Employee(id, name, dSelect); break;
			case 2:worker = new Manager(id, name, dSelect); break;
			case 3:worker = new Boss(id, name, dSelect); break;

			default:
				break;
			}
			
			
			//将创建的职工的指针保存到数组里里面
			newSpace[this->m_EmpNum + i] = worker;
			

		}
		//释放原有的空间
		delete[]this->m_EmpArray;
		//更改新的空间的指向
		this->m_EmpArray = newSpace;
		//更新职工的人数
		this->m_EmpNum = newSize;
		
		

		this->m_FileIsEmpty = false;
		cout << "成功添加了" << addNum << "名新的员工" << endl;
		
		
		//保存数据到文件中
		
	}
	else 
	{
		cout << "输入有误" << endl;
	}
	
	
	this->save();
	
	system("pause");
	system("cls");
}
bool  WorkerManager:: Exist_Id(int id)
{
	bool flag = false;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			flag = true;
			break;
		}
	}
	return true;
}
void WorkerManager :: save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式写文件
	
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
		
	}
	ofs.close();
}
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或者文件不存在，无法输出" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口
			 this->m_EmpArray[i]->showInfo() ;
		}
		
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist_emp(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Del_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空，没有什么可以再删除的了" << endl;
		return;
	}
	int choice;
	int num;
	cout << "请输入你想要删除的员工的编号:";
	cin >> choice;
	num = this->IsExist_emp(choice);
	if (num == -1)
	{
		cout << "对不起哦，该名员工不存在" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;
		this->save();
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_emp()
{
	if (this->m_FileIsEmpty)

	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号:" << endl;
		int id;
		cin >> id;
		int ret;
		ret = this->IsExist_emp(id);
		if (ret == -1)
		{
			cout << "对不起查无此人" << endl;
		}
		else
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查到： " << id << "号职工，请输入新的职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1.普通的职工" << endl;
			cout << "2.一般的经理" << endl;
			cout << "3.优秀的老板" << endl;

			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1:worker = new Employee(newId, newName, dSelect); break;
			case 2:worker = new Manager(newId, newName, dSelect); break;
			case 3:worker = new Boss(newId, newName, dSelect); break;

			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			this->save();
			system("pause");
			system("cls");
		}
	}
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在，" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1.按照职工的编号查找" << endl;
		cout << "2.按照职工的姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号
			int id;
			cout << "请输入要查找的职工编号:" << endl;
			cin >> id;
			int ret = IsExist_emp(id);
			if (ret != -1)
			{
				//找到
				cout << "查找成功" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名
			string name;
			cout << "请输入查找的姓名:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为:" 
						<< this->m_EmpArray[i]->m_Id 
						<< endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "查找失败" << endl;
			}
		}
		else
		{
			cout << "输入错误选项" << endl;
			
		}

	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式" << endl;
		cout << "1 按照职工号进行升序排" << endl;
		cout << "0 按照职工号进行降序排" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if(i != minOrMax)
			{
				Worker * temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		
		}
		this->save();
		this->Show_Emp();
	}
}
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式  ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
		}
		this->m_EmpNum = 0;
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
	}
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}