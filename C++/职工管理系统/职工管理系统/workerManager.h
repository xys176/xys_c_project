#pragma once           //��ֹͷ�ļ��ظ�����
#include <iostream>    //�������������
using namespace std;   //��׼�����ռ�
#include"worker.h"
#include<fstream>
#define FILE "testfile.txt"
class WorkerManager
{
public:
	WorkerManager();
	void Show_Menu();
	void Exit_System();


	void Add_Worker();
	void save();

	//��¼ְ������
	int m_EmpNum;
	Worker ** m_worker;
	~WorkerManager();


private:

};