#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ʾ��λ����
	virtual string getDeptName();
};