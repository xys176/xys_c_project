#include"student.h"
#include"globalFile.h"
#include<fstream>

//默认构造函数
Student::Student()
{

}
//有参构造函数,学号，姓名，密码
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		//将读取的信息放到容器
		vCom.push_back(com);	
	}
}
//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//申请预约
void Student::applyOrder()
{
	cout << "机房开放的时间为周一到周五" << endl;
	cout << "1，周一" << endl;
	cout << "2，周二" << endl;
	cout << "3，周三" << endl;
	cout << "4，周四" << endl;
	cout << "5，周五" << endl;
	cout << "请输入申请预约的时间" << endl;
	int date = 0;  //日期
	int interval = 0;  //时间段
	int room = 0;  //机房号
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "时间选择有误，请重新输入" << endl;
	}
	cout << "请输入申请的时间段，上午为“1\",下午为”2\""<<endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "时间段选择有误，请重新输入" << endl;
	}
	cout << "请选择机房" << endl;
	for (int i = 0;i < vCom.size();i++) {
		cout << vCom[i].m_ComId << "号机房的容量为" << vCom[i].m_MaxNum<<endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= vCom.size())
		{
			break;
		}
		cout << "机房选择有误，请重新输入" << endl;
	}
	cout << "预约申请成功，正在审核中" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "room:" << room << " ";
	ofs << "statue:" << 1 << endl;  //当前的预约状态
	
	ofs.close();
	system("pause");
	system("cls");
}
//查看自己的预约
void Student::showMyorder()
{
	OrderFile of;
	if (of.m_size == 0) {
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))   //找到自身的预约
			//string 转 int
			//string 利用 .c_str() 转 const char*
			//利用 atoi (const char*) 转 int
		{
			cout << "预约周期:周" << of.m_orderData[i]["date"];
			cout << "  时间段:" << (of.m_orderData[i]["interval"]=="1"?"上午":"下午");
			cout << "  预约机房编号:" << of.m_orderData[i]["room"];
			string status = "  当前预约状态：";
				//1 审核中  2 已预约  -1 预约失败  0 取消预约
			if (of.m_orderData[i]["statue"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["statue"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["statue"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");

}
//查看所有人的预约
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		cout << "第"<<i + 1<<"条预约记录： ";

		cout << "预约日期： 周" << of.m_orderData[i]["date"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.m_orderData[i]["stuId"];
		cout << " 姓名：" << of.m_orderData[i]["stuName"];
		cout << " 机房：" << of.m_orderData[i]["room"];
		string status = "的状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.m_orderData[i]["statue"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["statue"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["statue"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}
//取消预约
void Student:: canceOrder()
{

}
//学生学号
int m_Id;