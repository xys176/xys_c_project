#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"Manager.h"


Manager::Manager(int id, string name, int Did) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = Did;

}

//显示个人信息
void Manager::getInfo() {
	cout << "职工编号" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t职工岗位" << this->getDeptname()
		<< "\t岗位职责：完成老板任务给员工下达任务" << endl;
}
//获取岗位信息
string Manager::getDeptname() {
	return "经理";
}