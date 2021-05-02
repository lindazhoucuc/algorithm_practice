//
// Created by zhouxiaomin on 2021/05/02.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution slu;
    int res = slu.jump(nums);
    cout << res << endl;
}