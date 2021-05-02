//
// Created by zhouxiaomin on 2021/05/02.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//回溯法
//填一个数，验证是否有效，如果有效就接着往下走，否则恢复
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num)  return false;
            if(board[row][i] == num)  return false;
            int rowIndex = (row / 3) * 3;
            int colIndex = (col / 3) * 3;
            if(board[rowIndex + (i / 3)][colIndex + (i % 3)] == num)  return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] != '.')  continue;
                for(char num = '1'; num <= '9'; num++) {
                    if(isValid(board, i, j, num)) {
                        board[i][j] = num;
                        if(helper(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
};

int main() {
    for(char k = '0'; k < '9'; k++) {
        cout << k << endl;
    }
}
