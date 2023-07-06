
     // Leetcode problem no- 1493

// 1493. Longest Subarray of 1's After Deleting One Element
// Medium
// 3K
// 50
// Companies
// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         vector<int> res;
         int sum =0, n= nums.size();
         for(int i=0;i<n;i++){
           sum+=nums[i];
           if(nums[i]==0){
             res.push_back(sum);
             res.push_back(0);
             sum=0;
           }
           if(i==n-1){
             res.push_back(sum);
           }
         }
         int maxi =*max_element(res.begin(), res.end());
         for(int i=0;i<res.size();i++){
           int l=0,r=0;
           if(res[i] ==0) {
             if(i>0)l=res[i-1];
             if(i<n-1) r= res[i+1];
             maxi = max(maxi, l+r);
           }
         }
         return maxi==n? maxi-1: maxi;
    }
};
