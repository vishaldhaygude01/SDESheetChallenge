class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count++;
            }
            else{
                count = 0;
            }
            maxcnt = max(maxcnt,count);
        }
        return maxcnt;
    }
};