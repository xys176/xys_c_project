#pragma once
#include<iostream>
using namespace std;
class Worker
{
public:
	int m_id;
	string m_name;
	int m_deptid;
	//��ʾ������Ϣ
	virtual void getInfo() = 0;
	//��ȡ��λ��Ϣ
	virtual string getDeptname() = 0;


private:

};


