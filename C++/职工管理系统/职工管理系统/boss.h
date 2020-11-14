#pragma once
#include<iostream>
using namespace std;
#include"worker.h"


class boss :public Worker
{
public:
	boss(int id, string name, int Did);
	int m_deptid;
	//显示个人信息
	virtual void getInfo();
	//获取岗位信息
	virtual string getDeptname();

private:

};
