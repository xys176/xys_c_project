#pragma once
#include<iostream>
#include<string>
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
using namespace std;

//����Ա��
class Manager :public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Manager();
	//�вι��캯��
	Manager(string name, string pwd);
	//��¼����
	void operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴��������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();
	//����ظ�  ����1��ѧ����/��ʦ�ţ�����2���˺�����
	bool cheakRepeat(int id,int type);
	//��ʼ������
	void initvector();
	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;
	//��������,�洢��������Ϣ
	vector<ComputerRoom>vCom;
};