#include<iostream>
using namespace std;
enum ret { kvalid = 0, kinvalid };    // 是否有非法输入的标记
int status = kvalid;
long long Strtointcode(const char* digit, bool minus)
{
    long long num = 0;
    while (*digit != '\0')
    {
        if (*digit >= '0' && *digit <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');
            if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }
    if (*digit == '\0')
        status = kvalid;
    return num;
}
int Strtoint(const char* str)
{
    status = kinvalid;
    long long num = 0;
    if (str != NULL && *str != '\0')  
    {
        bool minus = false;
        if (*str == '+')
            str++;
        else if (*str == '-')
        {
            str++;
            minus = true;
        }
        if (*str != '\0')
            num = Strtointcode(str, minus);

    }
    return (int)num;
}

int main()
{
    string str;
    int ret = 0;
    cin >> str;
    ret = Strtoint(str.c_str());
    if (kvalid == status)
    {
        printf("%d\n", ret);
    }
    else
    {
        printf("输入非法\n");
        printf("%d\n", ret);
    }
    system("pause");
    return 0;
}