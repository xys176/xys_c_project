#pragma once
#include<iostream>
using namespace std;
#include"worker.h"


class boss :public Worker
{
public:
	boss(int id, string name, int Did);
	int m_deptid;
	//��ʾ������Ϣ
	virtual void getInfo();
	//��ȡ��λ��Ϣ
	virtual string getDeptname();

private:

};
