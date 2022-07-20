/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

class Solution{
public:
    
    //SPACE OPTIMAIZATION
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int>prev(m+1,0),cur(m+1,0);
      
        for(int j=0;j<=m;j++) prev[j] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]) cur[j] = 1 + prev[j-1];
        
                else cur[j] = max(prev[j] , cur[j-1]);
            }
            prev = cur;
        }
        return prev[n];
    }
};

/*
    
    int f(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return 1 + f(i-1,j-1,s,t,dp);
        
        return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
    }
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
    
    //TABULATION
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
      
      
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    
*/