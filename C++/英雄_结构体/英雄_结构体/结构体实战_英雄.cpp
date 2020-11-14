#include<iostream>
#include<string>
using namespace std;

struct Hero
{
	string name;
	int age;
	string sex;

};

void bubblesort(Hero heroArray[], int len) {
	for (int i = 0;i < len;i++) {
		for (int j = 0;j < len - i - 1;j++) {
			if (heroArray[j].age > heroArray[j + 1].age) {
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

void printfhero(Hero heroArray[], int len) {
	for (int i = 0;i < len;i++) {
		cout << "姓名" << heroArray[i].name << " 年龄" << heroArray[i].age << " 性别" << heroArray[i].sex << endl;
	}
}

int main() {
	//1.设计英雄结构体
		
	//2.创建数组存放英雄
	struct Hero heroArray[5] =
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	for (int i = 0;i < len;i++) {
		cout << "姓名" << heroArray[i].name << " 年龄" << heroArray[i].age << " 性别" << heroArray[i].sex << endl;
	}
	//3.对数组进行排序，按年龄升序排列
	bubblesort(heroArray, len);
	cout << "排序之后的结果" << endl;
	printfhero(heroArray, len);
	system("pause");



}