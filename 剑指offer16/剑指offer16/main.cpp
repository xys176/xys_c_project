#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            long num = n;
            num = -num;
            double result = pow(x, num);
            return 1.0 / result;
        }
        return pow(x, n);
    }
    double pow(double x, long n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        double result = myPow(x, n >> 1);
        result *= result;
        if (n & 0X1 == 1)
        {
            result *= x;
        }
        return result;
    }
};

int main()
{
	
    string line;
    cin >> line;
    double nuProject1m=atof(line.c_str());
    cout.flags(ios::fixed);
    //cout << setprecision(6) << num << endl;
    cout << num << endl;
    cin >> line;
    int exponent = atoi(line.c_str());
    cout << exponent << endl;
    double res = Solution().myPow(num, exponent);

    cout << setprecision(6) << res << endl;;
    return 0;
}