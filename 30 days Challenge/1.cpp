class Solution {
    int N;
    void f(int ind, int k, vector<int>&ds, vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(ds);
            return;
        }
        if(ind>N)return ;
        ds.push_back(ind);
        f(ind+1, k-1,ds,ans);
        ds.pop_back();
        f(ind+1, k,ds,ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        N = n;
        vector<vector<int>> ans;
        vector<int> ds;
        f(1, k,ds, ans);       

        return ans;
    }
};