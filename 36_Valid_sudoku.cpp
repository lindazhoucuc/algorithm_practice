//
// Created by zhouxiaomin on 2021/05/01.
//
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

//对于当前board[i][j] 检查当前所处行、列、小方块，没有重复的
class Solution {
public:
    //方法1 Runtime 12 ms	Memory18 MB
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                char key = board[i][j];
                if(key == '.') continue;
                if(!valid(board, i, j, key))    return false;
            }
        }
        return true;
    }

    bool valid(vector<vector<char>>& board, int row, int col, char key) {
        //row check
        for(int i=0; i<9; i++) {
            if(board[row][i] == key && i!=col) return false;
        }
        //col check
        for(int i=0; i<9; i++) {
            if(board[i][col] == key && i!=row) return false;
        }
        //subbox check
        int rowIndex = row/3 * 3;
        int colIndex = col/3 * 3;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[rowIndex+i][colIndex+j] == key && (rowIndex+i != row) && (colIndex+j != col))
                    return false;
            }
        }
        return true;
    }

    //方法2 Runtime 28 ms	Memory20.1 MB
    bool isValidSudoku2(vector<vector<char>>& board) {
        set<string> myset;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char ch = board[i][j];
                if(ch == '.') continue;

                string key = string(1, ch);
                string inRow = key + "in row" + to_string(i);
                string inCol = key + "in col" + to_string(j);
                int rowIndex = i/3;
                int colIndex = j/3;
                string inSubBox = key + "in subbox" + to_string(rowIndex) + to_string(colIndex);

                if(myset.find(inRow) != myset.end() || myset.find(inCol) != myset.end() ||
                        myset.find(inSubBox) != myset.end()) {
                    return false;
                } else {
                    myset.insert(inRow);
                    myset.insert(inCol);
                    myset.insert(inSubBox);
                }
            }
        }
        return true;
    }

};


int main() {
    char ch = '5';
    string t = string(3, ch);   //string 构造函数 fill string (size_t n, char c);
    cout << t << endl;
}

