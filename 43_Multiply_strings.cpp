//
// Created by zhouxiaomin on 2021/06/06.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//要点：1、长度分别为n1和n2的两数相乘结果长度最长等于n1+n2  所以可以初始化结果的长度为n1+n2的0
//2、位置i的数成衣位置j的数乘积是放在结果的i+j+1位上，如有进位放在i+j位上
//3、结果的leading zero问题，需要判断下是否见过非零数

class Solution{
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<char> res(n1 + n2, '0');
        for(int j = n2 - 1; j >= 0; j--) {
            for(int i = n1 - 1; i >= 0; i--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int tmp = (res[i + j + 1] - '0') + product;
                res[i + j + 1] = (tmp % 10) + '0';
                res[i + j] = ((res[i + j] - '0') + (tmp / 10)) + '0';
            }
        }

        string str = "";
        bool seen = false;
        for(char c: res) {
            if(!seen && c == '0') continue;
            else {
                seen = true;
                str += c;
            }
        }
        if(!seen) return "0";
        else return str;
    }

    string multiply2(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> res(n1 + n2, 0);
        for(int j = n2 - 1; j >= 0; j--) {
            for(int i = n1 - 1; i >= 0; i--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int tmp = res[i + j + 1] + product;
                res[i + j + 1] = tmp % 10;
                res[i + j] += tmp / 10;
            }
        }

        bool seen = false;
        string str = "";
        for(int d: res) {
            if(d == 0 && !seen)  continue;
            else {
                str += (d + '0');
                seen = true;
            }
        }
        if(!seen)   return "0";
        else    return str;

    }
};

int main() {
    string a = "123";
    string b = "456";
    Solution slu;
    string r = slu.multiply2(a, b);
    cout << r << endl;
}