#include<iostream>
#include<string>
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"workerManager.h"
int main()
{
	WorkerManager person;
	/*Worker *worker = NULL;
	worker = new Employee(1, "kcy", 1); 
	worker->getDeptName();
	worker->showInfo();*/  

	int choice;

	while (1)
	{
		person.Show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:person.exitSystem();
			break;
		case 1:system("cls"); person.Add_Emp();
			break;
		case 2:system("cls"); person.Show_Emp();
			break;
		case 3:system("cls"); person.Del_emp();
			break;
		case 4:system("cls"); person.Mod_emp();
			break;
		case 5:system("cls"); person.Find_Emp();
			break;
		case 6:system("cls"); person.Sort_Emp();
			break;
		case 7:system("cls"); person.Clean_File();
			break;
		default:
			cout << "请输入有效的选项" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
