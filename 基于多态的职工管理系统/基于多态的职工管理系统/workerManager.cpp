#include"workerManager.h"
#include<iostream>
using namespace std;
WorkerManager::WorkerManager()
{
	//�ļ������� 
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		/*cout << "�ļ�������" << endl;*/
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�����û����
	char ch;
	ifs >> ch; 
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		/*cout << "�ļ�������" << endl;*/
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		return;

	}
	//�ļ����ڣ�����������
	int num = this->get_EmpNum();
	this->m_EmpNum = num; 
	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//���ļ��е����ݴ浽������
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
		if (dId == 1)//ְ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index++] = worker;
	}
	ifs.close();

}
//չʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "\n\n\t\t\t\t��ӭʹ��ְ������ϵͳ" << endl;
	cout << "\t\t\t\t0.�˳�����ϵͳ" << endl;
	cout << "\t\t\t\t1.����ְ������Ϣ" << endl;
	cout << "\t\t\t\t2.��ʾְ������Ϣ" << endl;
	cout << "\t\t\t\t3.ɾ����ְְ������Ϣ" << endl;
	cout << "\t\t\t\t4.�޸�ְ����Ϣ" << endl;
	cout << "\t\t\t\t5.����ְ����Ϣ" << endl;
	cout << "\t\t\t\t6.���ձ������" << endl;
	cout << "\t\t\t\t7.������е��ĵ�\n\n" << endl;
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
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); 
}
void WorkerManager::Add_Emp()
{
	cout << "��������ӵ�ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	
	
	if (addNum > 0)
	{
		//������ӵ��µĿռ�Ĵ�С  ��������һ���ռ�
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker*[newSize];
		//���ԭ��������  ��Ҫ�Ȱ�ԭ��������ӽ�ȥ
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//����µ�����
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "��Ա���ı�ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��Ա����������" << endl;
			cin >> name;
			cout << "��ѡ���" << i + 1 << "��Ա���ĸ�λ" << endl;
			cout << "1.��ͨ��ְ��" << endl;
			cout << "2.һ��ľ���" << endl;
			cout << "3.������ϰ�" << endl;
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
			
			
			//��������ְ����ָ�뱣�浽����������
			newSpace[this->m_EmpNum + i] = worker;
			

		}
		//�ͷ�ԭ�еĿռ�
		delete[]this->m_EmpArray;
		//�����µĿռ��ָ��
		this->m_EmpArray = newSpace;
		//����ְ��������
		this->m_EmpNum = newSize;
		
		

		this->m_FileIsEmpty = false;
		cout << "�ɹ������" << addNum << "���µ�Ա��" << endl;
		
		
		//�������ݵ��ļ���
		
	}
	else 
	{
		cout << "��������" << endl;
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
	ofs.open(FILENAME, ios::out);//������ķ�ʽд�ļ�
	
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
		cout << "�ļ�Ϊ�ջ����ļ������ڣ��޷����" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
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
		cout << "�ļ������ڻ����ļ�Ϊ�գ�û��ʲô������ɾ������" << endl;
		return;
	}
	int choice;
	int num;
	cout << "����������Ҫɾ����Ա���ı��:";
	cin >> choice;
	num = this->IsExist_emp(choice);
	if (num == -1)
	{
		cout << "�Բ���Ŷ������Ա��������" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_emp()
{
	if (this->m_FileIsEmpty)

	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��:" << endl;
		int id;
		cin >> id;
		int ret;
		ret = this->IsExist_emp(id);
		if (ret == -1)
		{
			cout << "�Բ�����޴���" << endl;
		}
		else
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽�� " << id << "��ְ�����������µ�ְ���ţ�" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1.��ͨ��ְ��" << endl;
			cout << "2.һ��ľ���" << endl;
			cout << "3.������ϰ�" << endl;

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
			cout << "�޸ĳɹ�" << endl;
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
		cout << "�ļ������ڣ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.����ְ���ı�Ų���" << endl;
		cout << "2.����ְ������������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ��
			int id;
			cout << "������Ҫ���ҵ�ְ�����:" << endl;
			cin >> id;
			int ret = IsExist_emp(id);
			if (ret != -1)
			{
				//�ҵ�
				cout << "���ҳɹ�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
		else if (select == 2)
		{
			//��������
			string name;
			cout << "��������ҵ�����:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ:" 
						<< this->m_EmpArray[i]->m_Id 
						<< endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "����ʧ��" << endl;
			}
		}
		else
		{
			cout << "�������ѡ��" << endl;
			
		}

	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ" << endl;
		cout << "1 ����ְ���Ž���������" << endl;
		cout << "0 ����ְ���Ž��н�����" << endl;
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
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ  ios::trunc �������ɾ���ļ������´���
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
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}