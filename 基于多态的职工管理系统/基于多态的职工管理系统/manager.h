#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
class Manager :public Worker
{
public:
	Manager(int id, string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ʾ��λ����
	virtual string getDeptName();
};
