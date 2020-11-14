#pragma once
#include"employee.h"


Employee::Employee(int id, string name, int DeptId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = DeptId;
}



void Employee::getInfo() {
	cout << "职工编号" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t职工岗位" << this->getDeptname() 
		<< "\t岗位职责：完成经理的任务"<<endl;

}

string Employee::getDeptname() {
	return "员工";
}