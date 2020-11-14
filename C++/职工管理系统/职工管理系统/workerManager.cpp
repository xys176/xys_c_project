#include"workerManager.h"
#include"boss.h"
#include"employee.h"
#include"Manager.h"
#include<fstream>

WorkerManager::WorkerManager()
{
	this->m_EmpNum = 0;
	this->m_worker = NULL;
}

WorkerManager::~WorkerManager()
{
	if (this->m_worker != NULL) {
		delete[]this->m_worker;
		this->m_worker = NULL;
	}

}

void WorkerManager::Show_Menu() {
	cout << "************************" << endl;
	cout << "**欢迎使用职工管理系统**" << endl;
	cout << "*******0.退出系统*******" << endl;
	cout << "*******1.增加职工*******" << endl;
	cout << "*******2.显示职工*******" << endl;
	cout << "*******3.删除职工*******" << endl;
	cout << "*******4.修改职工*******" << endl;
	cout << "*******5.查找职工*******" << endl;
	cout << "*******6.职工排序*******" << endl;
	cout << "*******7.清空数据*******" << endl;
	cout << "************************" << endl;
	cout << endl;
}

void WorkerManager::Exit_System() {
	cout << "已退出系统欢迎下次使用" << endl;
	cout << "按任意键退出" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Worker() {
	cout << "请输入添加的职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum <= 0) {
		cout<<"输入有误"<<endl;
	}
	else {
		//添加
		//计算添加的新空间大小
		int newSize = m_EmpNum + addNum;
		//开辟新空间,新建一个可以存储newsize个大小的指针数组，数组里面存储的是指针，每个指针指向一个Worker对象。
		//newspace是指向指针数组的指针。
		Worker** newspace = new Worker * [newSize];
		//将原来的数据拷贝到新开辟的空间下
		if (this->m_EmpNum != NULL) {
			for (int i = 0;i < this->m_EmpNum;i++) {
				newspace[i] = this->m_worker[i];
			}
		}
		//批量添加职工
		for (int i = 0;i < addNum;i++) {
			int id;
			string name;
			int dSelect=0;
			cout << "请输入" << i + 1 << "个职工编号" << endl;
			cin >> id;
			cout << "请输入" << i + 1 << "个职工姓名" << endl;
			cin >> name;
			cout << "请输入" << i + 1 << "个职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,dSelect);
			case 2:
				worker = new Manager(id, name, dSelect);
			case 3:
				worker = new boss(id, name, dSelect);
			default:
				break;
			}
			//将创建的职工，保存到数组
			newspace[this->m_EmpNum + i] = worker;
		}
		delete[]this->m_worker;
		this->m_worker = newspace;
		this->m_EmpNum = newSize;
		this->save();
		cout << "成功添加" << addNum << "名职工" << endl;

		system("pause");

		system("cls");
	}
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILE,ios::out);  //用输出的方式打开文件，就是向文件中写入数据
	for (int i = 0;i < this->m_EmpNum;i++) {
		ofs << m_worker[i]->m_id << " " 
			<< m_worker[i]->m_name << " " 
			<< m_worker[i]->m_deptid << endl;
	}
	ofs.close();
}
