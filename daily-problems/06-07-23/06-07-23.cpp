 // problem no--209
// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0, sum=0, mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target && j<=i){
                mini= min(mini, i-j+1);
                sum-=nums[j++];
            }
        }
        return (mini==INT_MAX)? 0: mini;
    }
};