/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
         unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
        
        
        
        return -1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
        
        
        */
        int ans = 0;
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(count == 0){
                ans = num;
            }
            if(num == ans){
                count++;
            }
            else{
                count--;
            }
        }
        return ans;
    }
};