//
// Created by zhouxiaomin on 2021/04/07.
//
/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1


Constraints:

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 104
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这是方法1，DP，复杂度N^2
//还有更简单的NlogN解法,need review
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), myfunction);
        vector<int> dp(envelopes.size(), 1);
        for(int i = 0; i < envelopes.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

private:
    static bool myfunction(vector<int> left, vector<int> right) {
        if(left[0] == right[0])    return left[1] < right[1];
        else   return left[0] < right[0];
    }
};

int main(){
    vector<vector<int>> input = { {5, 4}, {6, 4}, {6, 7}, {2, 3},};
    Solution slu;
    int res = slu.maxEnvelopes(input);
    cout << res << endl;

}