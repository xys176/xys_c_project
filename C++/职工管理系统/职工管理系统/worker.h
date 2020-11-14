#pragma once
#include<iostream>
using namespace std;
class Worker
{
public:
	int m_id;
	string m_name;
	int m_deptid;
	//显示个人信息
	virtual void getInfo() = 0;
	//获取岗位信息
	virtual string getDeptname() = 0;


private:

};


