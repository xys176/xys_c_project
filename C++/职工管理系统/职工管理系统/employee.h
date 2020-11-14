#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Employee:public Worker
{
public:
	Employee(int id,string name,int DeptId);

	//显示个人信息
	virtual void getInfo();
	//获取岗位信息
	virtual string getDeptname();
private:

};

