#pragma once
#include"employee.h"


Employee::Employee(int id, string name, int DeptId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = DeptId;
}



void Employee::getInfo() {
	cout << "ְ�����" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\tְ����λ" << this->getDeptname() 
		<< "\t��λְ����ɾ��������"<<endl;

}

string Employee::getDeptname() {
	return "Ա��";
}