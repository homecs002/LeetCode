#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        vector<int> ans;

        if(s_len < p_len) return ans; 

        
        vector<int>p_count(26);
        for(int i = 0; i < p_len; i++){
            p_count[p[i] - 'a'] += 1;
        }

        for (int i = 0; i < s_len; i++){
            vector<int>s_count(26);
            for (int j = 0; j < p_len && i + j < s_len; j++){
                s_count[s[i + j] - 'a'] += 1;
            }
            if(s_count == p_count) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    // 定义好函数中的测试数据
    string s = "cbaebabacd";
    string p = "abc";
    
    Solution solu;
    vector<int> ans = solu.findAnagrams(s, p);
    
    return 0;
}