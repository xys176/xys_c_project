#include<iostream>
#include<string>
#include <cassert>


using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        int n = num.size(), m = n - k;
        for (int i = 0;i < num.size();i++) {
            while (k && result.size() && result.back() > num[i]) {
                result.pop_back();
                --k;
            }
            result.push_back(num[i]);
        }
        result.resize(m);
        //去除前导0， 如10200，k = 1
        while (!result.empty() && result[0] == '0') {
            result.erase(result.begin());
        }
        return result.empty() ? "0" : result;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"': result.push_back('\"'); break;
            case '/': result.push_back('/'); break;
            case '\\': result.push_back('\\'); break;
            case 'b': result.push_back('\b'); break;
            case 'f': result.push_back('\f'); break;
            case 'r': result.push_back('\r'); break;
            case 'n': result.push_back('\n'); break;
            case 't': result.push_back('\t'); break;
            default: break;
            }
            i++;
        }
        else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num = line;
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().removeKdigits(num, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
