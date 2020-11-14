#pragma once
#include<iostream>
#include"identity.h"
using namespace std;

//老师类
class Teacher :public Identity
{
public:
	//默认构造函数
	Teacher();
	//有参构造函数
	Teacher(int empId, string name, string pwd);
	//登录菜单
	virtual void operMenu();
	//查看所有人的预约
	void showAllOrder();
	//审核预约
	void valideOrder();
	//职工编号
	int m_EmpId;
};