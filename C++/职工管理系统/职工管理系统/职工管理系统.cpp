#include<iostream>
#include<string>
#include"workerManager.h"
#include"employee.h"
#include"Manager.h"
#include"boss.h"
#include"worker.h"
using namespace std;

int main()
{
	//管理者对象
	WorkerManager worker_m1;
	//Worker* worker = new Employee(1, "zahngsan", 1);
	//worker->getInfo();
	//delete worker;
	//Worker* worker1 = new Manager(1, "zahngsan", 1);
	//worker->getInfo();
	//delete worker1;
	//Worker* worker2 = new boss(1, "zahngsan", 1);
	//worker->getInfo();
	//delete worker2;
	
	int choice = 0;
	while(true){
		worker_m1.Show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			worker_m1.Exit_System();
			break;
		case 1:
			worker_m1.Add_Worker();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}