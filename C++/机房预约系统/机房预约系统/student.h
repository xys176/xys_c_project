#pragma once
#include<iostream>
#include"computerRoom.h"
#include<vector>
using namespace std;
#include "identity.h"
#include"orderFile.h"
//ѧ����
class Student :public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Student();
	//�вι��캯��,ѧ�ţ�����������
	Student(int id,string name,string pwd);
	//�˵�����
	void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�Լ���ԤԼ
	void showMyorder();
	//�鿴�����˵�ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void canceOrder();
	//ѧ��ѧ��
	int m_Id;
	//��������
	vector<ComputerRoom>vCom;
};