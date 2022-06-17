/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

*/

class Solution {
public:
    void subSets(int idx,vector<int>& nums, vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=idx;i<nums.size();i++){
            if(i != idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            subSets(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        subSets(0,nums,ds,ans);
        return ans;
    }
};