#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>

class OrderFile
{
public:
	//���캯��
	OrderFile();
	//����ԤԼ
	void updateOrder();
	//��¼ԤԼ����
	int m_size;
	//��¼����ԤԼ������
	map<int, map<string, string>>m_orderData;  //key��¼����������value��¼����ļ�ֵ�Ե���Ϣ
};