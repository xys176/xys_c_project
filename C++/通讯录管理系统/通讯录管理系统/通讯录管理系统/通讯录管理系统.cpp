#include<iostream>
#include<Windows.h>
using namespace std;
#define MAX 1000
struct Person
{
	string name;
	int age;
	int sex;
	string telephone;
	string address;
};

struct Addressbook
{
	struct Person personArray[MAX];
	int size;
};

//菜单
void showMean() {
	cout << "************" << endl;
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "0.退出通讯录" << endl;
}
//添加联系人

void AddPerson(Addressbook* abs) {
	if (abs->size == MAX) {
		cout << "通讯录已满" << endl;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;
		while (true) {
			int sex;
		    cout << "请输入性别,1代表男，2代表女" << endl;
		    cin >> sex;
		    if (sex == 1 || sex == 2) {
			    abs->personArray[abs->size].sex = sex;
			    break;  //输入错误，重新输入
		       }
		         cout << "请重新输入" << endl;
	    }
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->size].age = age;
		cout << "请输入号码" << endl;
		string telephone;
		cin >> telephone;
		abs->personArray[abs->size].telephone = telephone;
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->size].address = address;
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}

}

//显示所有的联系人
void ShowPerson(Addressbook *abs) {
	if (abs->size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0;i < abs->size;i++) {
			cout << "姓名：" << abs->personArray[i].name << "\t";
			cout << "性别：" << (abs->personArray[i].sex == 1 ?"男":"女")<< "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "号码：" << abs->personArray[i].telephone << "\t";
			cout << "住址：" << abs->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，存在返回数组中的下标，不存在返回-1
int isExist(Addressbook* abs,string name) {
	for (int i = 0;i < abs->size;i++) {
		if (abs->personArray[i].name == name) {
			return i;
		}
		return - 1;
	}
}

//删除指定的联系人
void deletePerson(Addressbook* abs) {
	cout << "输入要删除联系人得姓名" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result != -1) {
		cout << "没有此人无法删除" << endl;
	}
	else {
		for (int i = result;i < abs->size;i++) {
			abs->personArray[i] = abs->personArray[i + 1];   //数据从要删除的位置之后向前移
		 }
		abs->size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbook* abs) {
	cout << "请输入要查找的联系人" << endl;
	if (abs->size == 0) {
		cout << "通讯录为空，没有联系人"<<endl;
	}
	else {
		string name1;
		cin >> name1;
		int ret = isExist(abs, name1);
		if (ret != -1) {
			cout << "姓名" << abs->personArray[ret].name << "\t";
			cout << "年龄" << abs->personArray[ret].age << "\t";
			cout << "性别" << abs->personArray[ret].sex << "\t";
			cout << "号码" << abs->personArray[ret].telephone << "\t";
			cout << "地址" << abs->personArray[ret].address << endl;
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改联系人
void modiyPerson(Addressbook* abs) {
	cout << "输入想要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入修改后的姓名" << endl;
		cin >> name;
		abs->personArray[ret].name = name;
		int sex = 0;
		while (true) {
			cout << "请输入修改后的性别,1代表男，2代表女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].sex = sex;
				break;
			}
			cout << "请重新输入" << endl;
		}
		cout << "请输入修改后的年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].age = age;
		cout << "请输入修改后的号码" << endl;
		string telephone;
		cin >> telephone;
		abs->personArray[ret].telephone = telephone;
		cout << "请输入修改后的地址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].address = address;
		cout << "修改成功" << endl;	
		cout << "修改后的联系人信息" << endl;
		ShowPerson(abs);
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void clearPerson(Addressbook* abs) {
	abs->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main() {
	Addressbook abs;
	//初始化通讯录
	abs.size = 0;


	int select = 0;
	while (true) {
		showMean();
		cout << "请输入" << endl;
		cin >> select;
		switch (select) {
		case 1:  //1.添加联系人
			AddPerson(&abs);   //若用值传递实参无法改变，必须要用传递地址
			break;
		case 2:  //2.显示联系人
			ShowPerson(&abs);
			break;
		case 3:  //3.删除联系人
		{
			//cout << "请输入删除联系人的姓名" << endl;
			//string nametemp;
			//cin >> nametemp;
			//if (isExist(&abs, nametemp) == -1) {
			//	cout << "查无此人" << endl;
			//}
			//cout << "查到此人" << endl;
			deletePerson(&abs);
			break;
		}
		case 4:  //4.查找联系人
			findPerson(&abs);
			break;
		case 5:  //5.修改联系人
			modiyPerson(&abs);
			break;
		case 6:  //6.清空联系人
			clearPerson(&abs);
			break;
		case 0:  //0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误" << endl;
		}

	}

	system("pause");
	return 0;
}