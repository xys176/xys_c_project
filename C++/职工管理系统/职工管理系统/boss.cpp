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

//��ʾ������Ϣ
void boss::getInfo() {
	cout << "ְ�����" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\tְ����λ" << this->getDeptname()
		<< "\t��λְ���´�����" << endl;
}
//��ȡ��λ��Ϣ
string boss::getDeptname() {
	return "����";
}
