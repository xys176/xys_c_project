#pragma once
#include<iostream>
using namespace std;
#include"worker.h"


class Manager :public Worker
{
public:
	Manager(int id, string name, int Did);
	int m_deptid;
	//��ʾ������Ϣ
	virtual void getInfo() ;
	//��ȡ��λ��Ϣ
	virtual string getDeptname();

private:

};
