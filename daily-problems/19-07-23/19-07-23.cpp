class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& it) {  
        sort(it.begin(), it.end(),[&](vector<int>&a, vector<int>&b){return a[1]<b[1];});
        int l = it[0][1];
        int ans=0;
        for(int i=1;i<it.size();++i){
            if(it[i][0]>=l){
               l = it[i][1];
            }else {
                ans++;
            }
        }
        return ans; 
    }
};