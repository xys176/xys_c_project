#include<iostream>
#include<string.h>
#include<random>
#include<ctime>
using namespace std;

struct Student
{
	string name;
	int sorce;
};

struct Teacher
{
	string name;
	struct Student sArray[5];


};

void allocateSpace(struct Teacher tArray[], int len) {
	for (int i = 0;i < len;i++) {
		string nameSeed = "ABCDE";
		tArray[i].name = "Teacher_";
		tArray[i].name += nameSeed[i];
		for (int j = 0;j < 5;j++) {
			tArray[i].sArray[j].name = "Student_";
			tArray[i].sArray[j].name += nameSeed[j];
			int random = rand ()% 61+40;   //40~100
			tArray[i].sArray[j].sorce = random;
		}
	}
}

void printfInfo(struct Teacher tArray[], int len) {
	for (int i = 0;i < len;i++) {
		cout << "老师姓名" << tArray[i].name << endl;
		for (int j = 0;j < 5;j++) {
			cout << "学生姓名" << tArray[i].sArray[j].name << "学生分数" << tArray[i].sArray[j].sorce << endl;
		}
	}
}
int main() {
	srand((unsigned int)time(NULL));
	struct Teacher tArray[3];
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);
	printfInfo(tArray, len);
	system("pause");
}