#pragma once
#include<iostream>
#include<string>
using namespace std;


//ְ���ĳ������  Ϊ������������̳� 
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ʾ��λ����
	virtual string getDeptName() = 0;

	int m_Id;//ְ�����
	string m_Name;//ְ��������
	int m_DeptId;//ְ�����ڲ������Ʊ��
};


