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

//��ʾ������Ϣ
void Manager::getInfo() {
	cout << "ְ�����" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\tְ����λ" << this->getDeptname()
		<< "\t��λְ������ϰ������Ա���´�����" << endl;
}
//��ȡ��λ��Ϣ
string Manager::getDeptname() {
	return "����";
}