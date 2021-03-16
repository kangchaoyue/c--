
#pragma once//��ֹͷ�ļ��ظ�����
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
	//���캯��
	WorkerManager();

	//չʾ�˵�

	void Show_Menu();
	void exitSystem();//�˳�ϵͳ�ĳ�Ա����
  
	//��¼ְ��������
	int m_EmpNum = 0;

	//��¼ְ�������ָ��
	Worker ** m_EmpArray;
	//���ְ���ĺ���
	void Add_Emp();
	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ������Ϣ
	void Show_Emp();
	//ɾ��ְ��
	void Del_emp();
	//�ж�ְ���Ƿ����
	int IsExist_emp(int id); 
	//�޸�ְ������Ϣ
	void Mod_emp();
	//����Ա��
	void Find_Emp();
	//�жϵ�ǰ�Ĵ��������Id�Ƿ��Ѿ�����
	
	
	bool Exist_Id(int id);
	//��Ա����������
	void Sort_Emp();
	//���ļ��������
	void Clean_File();

	//��������

	
	~WorkerManager();




};