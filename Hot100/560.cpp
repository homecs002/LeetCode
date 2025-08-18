#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 前缀和
        // 生成前缀和：
        int len = nums.size();
        const int len_max = 2e4 + 5;
        int S[len_max] = {0};
        S[1] = nums[0];
        int cnt = 0;
        for (int i = 1; i < len + 1; i++){
            S[i] = S[i - 1] + nums[i - 1];
        } 
        // if (S[0] == k) cnt+=1;
        for (int i = 0; i < len + 1; i++){
            for (int j = i + 1; j < len + 1; j++){
                if(S[j] - S[i] == k) cnt += 1;
            }
        }
        return cnt;
    }
};

int main(){
    // 定义好函数中的测试数据
    vector<int> inp = {1,1,1};
    int k = 2;
    Solution solu;
    int ans = solu.subarraySum(inp, k);
    cout << ans;
    return 0;
}