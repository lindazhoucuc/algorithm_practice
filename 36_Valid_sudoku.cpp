//
// Created by zhouxiaomin on 2021/05/01.
//
#include <vector>
using namespace std;

//对于当前board[i][j] 检查当前所处行、列、小方块，没有重复的
class Solution {
public:
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
};


