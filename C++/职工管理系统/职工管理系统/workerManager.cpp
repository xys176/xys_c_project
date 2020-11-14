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
	cout << "**��ӭʹ��ְ������ϵͳ**" << endl;
	cout << "*******0.�˳�ϵͳ*******" << endl;
	cout << "*******1.����ְ��*******" << endl;
	cout << "*******2.��ʾְ��*******" << endl;
	cout << "*******3.ɾ��ְ��*******" << endl;
	cout << "*******4.�޸�ְ��*******" << endl;
	cout << "*******5.����ְ��*******" << endl;
	cout << "*******6.ְ������*******" << endl;
	cout << "*******7.�������*******" << endl;
	cout << "************************" << endl;
	cout << endl;
}

void WorkerManager::Exit_System() {
	cout << "���˳�ϵͳ��ӭ�´�ʹ��" << endl;
	cout << "��������˳�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Worker() {
	cout << "��������ӵ�ְ������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum <= 0) {
		cout<<"��������"<<endl;
	}
	else {
		//���
		//������ӵ��¿ռ��С
		int newSize = m_EmpNum + addNum;
		//�����¿ռ�,�½�һ�����Դ洢newsize����С��ָ�����飬��������洢����ָ�룬ÿ��ָ��ָ��һ��Worker����
		//newspace��ָ��ָ�������ָ�롣
		Worker** newspace = new Worker * [newSize];
		//��ԭ�������ݿ������¿��ٵĿռ���
		if (this->m_EmpNum != NULL) {
			for (int i = 0;i < this->m_EmpNum;i++) {
				newspace[i] = this->m_worker[i];
			}
		}
		//�������ְ��
		for (int i = 0;i < addNum;i++) {
			int id;
			string name;
			int dSelect=0;
			cout << "������" << i + 1 << "��ְ�����" << endl;
			cin >> id;
			cout << "������" << i + 1 << "��ְ������" << endl;
			cin >> name;
			cout << "������" << i + 1 << "��ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��������ְ�������浽����
			newspace[this->m_EmpNum + i] = worker;
		}
		delete[]this->m_worker;
		this->m_worker = newspace;
		this->m_EmpNum = newSize;
		this->save();
		cout << "�ɹ����" << addNum << "��ְ��" << endl;

		system("pause");

		system("cls");
	}
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILE,ios::out);  //������ķ�ʽ���ļ����������ļ���д������
	for (int i = 0;i < this->m_EmpNum;i++) {
		ofs << m_worker[i]->m_id << " " 
			<< m_worker[i]->m_name << " " 
			<< m_worker[i]->m_deptid << endl;
	}
	ofs.close();
}
