//
// Created by zhouxiaomin on 2021/05/02.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        if (n < 3)    return res;
        //动态规划
        vector<int> left_vec(n, 0);
        vector<int> right_vec(n, 0);
        left_vec[0] = height[0];
        right_vec[n-1] = height[n-1];
        //从左往右看，找到每个柱子左边最大值
        for(int i = 1; i < n; i++) {
            left_vec[i] = max(left_vec[i-1], height[i]);
        }
        //从右往左看，找到每个柱子右边最大值
        for(int i = n - 2; i >= 0; i-- ) {
            right_vec[i] = max(right_vec[i+1], height[i]);
        }
        //对每个柱子，其左边最大值&右边最大值的min 短板，减去自身的高度，就是这一个柱子能蓄水的高度
        for(int i = 0; i < n; i++) {
            res += (min(left_vec[i], right_vec[i]) - height[i]);
        }
        return res;
    }

    int trap2(vector<int>& height) {
        int res = 0;
        stack<int> st;
        int n = height.size();
        int i = 0;
        while(i < n) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if(st.empty()) break;
                int width = i - st.top() - 1;
                int bound_height = min(height[i], height[st.top()]) - height[top];
                res += width * bound_height;
            }
            st.push(i);
            i++;
        }
        return res;
    }
};

int main() {
    vector<int> input = {4, 2, 0, 5, 2, 3};
    Solution slu;
    int res = slu.trap2(input);
    cout << res << endl;
}