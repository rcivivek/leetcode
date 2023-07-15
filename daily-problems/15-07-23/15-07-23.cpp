class Solution {

    int n;
    int bs (int index, vector<vector<int>>&events, int target){
        int res=-1,low = index, high = events.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(events[mid][0]>target){
                res=mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        return res;
    }
    int f(int  ind,int k, vector<vector<int>>&events,vector<vector<int>>&dp){
        if(ind>=n || k==0 || ind==-1)return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        
        int index = bs(ind, events, events[ind][1]);
        int left = events[ind][2]+f(index, k-1, events,dp);
        int right = f(ind+1, k, events,dp);
        return dp[ind][k] = max(left, right);

    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(), [&](vector<int> a, vector<int>b){
            return a[0]<b[0];
        });
        n= events.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(0, k, events,dp);
    }
};