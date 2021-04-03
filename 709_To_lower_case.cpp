//
// Created by zhouxiaomin on 2021/04/04.
//
#include <iostream>
using namespace std;

//这个方法是利用字符对应的ascii码
//另一个方法可以写一个map记录大小写对应关系
class Solution {
public:
    string toLowerCase(string str) {
        string res;
        if (str == "") return res;
        for(unsigned int i=0; i<str.size(); i++) {
            int digit = str[i];
            if (digit>=65 && digit<=90) {
                char lower_char = digit + 32;
                res += lower_char;
            }else {
                res += str[i];
            }
        }
        return res;
    }
};

int main(){
    string input = "LOVELY";
    Solution slu = Solution();
    cout << input << '\t' << slu.toLowerCase(input) << endl;
    return 0;
}
