//
// Created by zhouxiaomin on 2021/04/05.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        if (num > 3999 || num < 1)    return ans;

        // unit  half  full
        vector<vector<char> > myvec = {
                {'I', 'V', 'X'},
                {'X', 'L', 'C'},
                {'C', 'D', 'M'},
                {'M', '0', '0'}
        };

        int count = 0;
        while(num > 0) {
            int digit = num % 10;
            num /= 10;
            string tmp = digit_to_string(digit, myvec[count]);
            ans = tmp + ans;

            count++;
        }
        return ans;
    }

private:
    string digit_to_string(int digit, vector<char> helpervec) {
        string res;
        char unit, half, full;
        unit = helpervec[0];
        half = helpervec[1];
        full = helpervec[2];

        if(digit == 4 || digit == 9) {
            res = unit;
            if(digit == 4) {
                res += half;
            }else {
                res += full;
            }
        } else if(digit >= 5) {
            res = half;
            digit -= 5;
        }
        if(digit < 4) {
            for(int i = 0; i < digit; i++) {
                res += unit;
            }
        }
        return res;
    }
};

int main() {
    Solution slu;
    int input = 3;

    string roman;
    roman = slu.intToRoman(input);
    cout << input << '\t' << roman << endl;
}