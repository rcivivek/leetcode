// Problem no -2551

#define ll long long int
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n= weights.size();
        vector<int> pair;
        for(int i=0;i<n-1;i++){
          pair.push_back(weights[i]+weights[i+1]);
        }
        sort(pair.begin(),pair.end());
        long long int ans =0;
        for(int i=0;i<k-1;i++){
            ans+=pair[n-2-i] - pair[i];
        }
        return ans;
    }
}; 