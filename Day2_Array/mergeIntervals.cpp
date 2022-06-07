class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.size() == 0) return ans;
        sort(intervals.begin(),intervals.end());
        vector<int>currInt = intervals[0];
        
        for(auto x : intervals){
            if(x[0] <= currInt[1]){
                currInt[1] = max(x[1],currInt[1]);
            }
            else{
                ans.push_back(currInt);
                currInt = x;
            }
        }
        ans.push_back(currInt);
        return ans;
    }
};
//TC -- O(NLOGN)+O(N)
