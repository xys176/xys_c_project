#include<stdio.h>
#include<Windows.h>

//����x��n����
double mypow(double x, int n) {
	if (x == 1 || n == 0)  //��xΪ1��nΪ0ʱ������Ľ������1���������
		return 1;
	double ans = 1;        
	long num = n;
	if (n < 0) {           //��nΪ����ʱ������1/x����ʽ
		num = -num;
		x = 1 / x;
	}
	while (num) {          //����һλ��ֱ����Ϊ��
		if (num & 1) {     //��Ϊ����ʱ��������1�η���ͨ��һ�δε�ѭ���ó����
			ans *= x;
		}
		x *= x;
		num >>= 1;
	}
	return ans;
}
int main() {


}