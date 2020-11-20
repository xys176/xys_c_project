#include<stdio.h>
#include<Windows.h>

//计算x的n次幂
double mypow(double x, int n) {
	if (x == 1 || n == 0)  //当x为1，n为0时，输出的结果就是1，单独输出
		return 1;
	double ans = 1;        
	long num = n;
	if (n < 0) {           //当n为负数时，化成1/x的形式
		num = -num;
		x = 1 / x;
	}
	while (num) {          //右移一位，直到不为零
		if (num & 1) {     //幂为奇数时，最后就是1次方。通过一次次的循环得出结果
			ans *= x;
		}
		x *= x;
		num >>= 1;
	}
	return ans;
}
int main() {


}