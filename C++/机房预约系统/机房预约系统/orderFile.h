#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>

class OrderFile
{
public:
	//构造函数
	OrderFile();
	//更新预约
	void updateOrder();
	//记录预约条数
	int m_size;
	//记录所有预约的容器
	map<int, map<string, string>>m_orderData;  //key记录的是条数，value记录具体的键值对的信息
};