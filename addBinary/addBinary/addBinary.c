char *addBinary(char *a, char *b) {
	int carry = 0;
	int length = (strlen(a) > strlen(b) ? strlen(a) + 2 : strlen(b) + 2);
	char *result = (char*)malloct(sizeof(char)*length);
	result[length - 1] = '0';       //给从左向右第二位赋初值0，用于第一次加数之后的进位判断。
	for (int i = strlen(a) - 1, j = strlen(b) - 1, k = length - 2;(i > 0) || (j > 0);i--, j--, k--) {
		//k是判断是否有进位的，初始值在二进制数长度的左边第二位
		int sum = carry;
		sum += (i >= 0 ? a[i] - '0' : 0);
		sum += (j >= 0 ? a[j] - '0' : 0);
		carry = sum / 2;           //若要进位carry就被置成1，在下一次for循环中首先就会加上1
		result[k]=sum%2+'0';       //+'0'是因为数组中的加减是用ASCII值中进行加减的,而k的值在向前移动，当两个数相加大于或等于2，
		                           //就会有1+‘0’=‘1’，给下一位进了一位1
	}
	if (carry == 0) {
		return result+1;
	}
	result[0] = "1";
	return result;
}