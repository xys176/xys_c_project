#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"


boss::boss(int id, string name, int Did) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = Did;

}

//显示个人信息
void boss::getInfo() {
	cout << "职工编号" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t职工岗位" << this->getDeptname()
		<< "\t岗位职责：下达任务" << endl;
}
//获取岗位信息
string boss::getDeptname() {
	return "经理";
}
