class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int> dp;
        int res=1;
        for(const int &it: arr){
            int prev = dp.count(it-d)? dp[it-d]:0;
            dp[it] = prev+1;
            res = max(res, dp[it]);
        }
        return res;
    }
};