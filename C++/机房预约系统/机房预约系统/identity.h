#pragma once   //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;

//��ݳ���Ļ��࣬ÿ����������������
class Identity 
{
public:
	//ÿ����ݺ��Ӧһ�ֵ�¼�˵������麯����ʵ���ھ������������
	virtual void operMenu() = 0;
	//�û���
	string m_Name;
	//����
	string m_Pwd;
};