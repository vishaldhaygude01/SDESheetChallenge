/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


BRUTE FORCE --
SORT ARRAY CHECK ADJECENT ELEMENT 
TC - O(NLOGN)


*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p = nums[0];
        int q = nums[0];
        do{
            p = nums[p];
            q = nums[nums[q]];
        }while(p != q);
        p = nums[0];
        while(p != q){
            p = nums[p];
            q = nums[q];
        }
        return p;
    }
};