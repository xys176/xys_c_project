#pragma once
#include<iostream>
#include"identity.h"
using namespace std;

//��ʦ��
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Teacher();
	//�вι��캯��
	Teacher(int empId, string name, string pwd);
	//��¼�˵�
	virtual void operMenu();
	//�鿴�����˵�ԤԼ
	void showAllOrder();
	//���ԤԼ
	void valideOrder();
	//ְ�����
	int m_EmpId;
};