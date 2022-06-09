/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hs;
        for(int num:nums){
            hs.insert(num);
        }
        int maxCount = 0;
        for(int num:nums){
            if(!hs.count(num-1)){
                int currentNum = num;
                int currCount = 1;
                
                while(hs.count(currentNum+1)){
                    currentNum++;
                    currCount++;
                }
                maxCount = max(maxCount,currCount);
            }
        }
        return maxCount;
    }
};