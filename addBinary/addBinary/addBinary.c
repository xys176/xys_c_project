char *addBinary(char *a, char *b) {
	int carry = 0;
	int length = (strlen(a) > strlen(b) ? strlen(a) + 2 : strlen(b) + 2);
	char *result = (char*)malloct(sizeof(char)*length);
	result[length - 1] = '0';       //���������ҵڶ�λ����ֵ0�����ڵ�һ�μ���֮��Ľ�λ�жϡ�
	for (int i = strlen(a) - 1, j = strlen(b) - 1, k = length - 2;(i > 0) || (j > 0);i--, j--, k--) {
		//k���ж��Ƿ��н�λ�ģ���ʼֵ�ڶ����������ȵ���ߵڶ�λ
		int sum = carry;
		sum += (i >= 0 ? a[i] - '0' : 0);
		sum += (j >= 0 ? a[j] - '0' : 0);
		carry = sum / 2;           //��Ҫ��λcarry�ͱ��ó�1������һ��forѭ�������Ⱦͻ����1
		result[k]=sum%2+'0';       //+'0'����Ϊ�����еļӼ�����ASCIIֵ�н��мӼ���,��k��ֵ����ǰ�ƶ�������������Ӵ��ڻ����2��
		                           //�ͻ���1+��0��=��1��������һλ����һλ1
	}
	if (carry == 0) {
		return result+1;
	}
	result[0] = "1";
	return result;
}