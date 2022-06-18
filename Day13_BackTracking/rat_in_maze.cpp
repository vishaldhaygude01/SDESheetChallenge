class Solution{
public:
    
    void solve(vector<vector<int>>&m, int n,int i, int j, string move,vector<string>&ans){
        if(i==n-1 && j==n-1){
            if(m[i][j] == 1){
                ans.push_back(move);
                return;
            }
        }
        if(i<0 || j<0 || i>=n || j>=n || m[i][j] == 0) return;
        m[i][j] = 0;
        //down
        solve(m,n,i+1,j,move+'D',ans);
        //left
        solve(m,n,i,j-1,move+'L',ans);
        //right
        solve(m,n,i,j+1,move+'R',ans);
        //up
        solve(m,n,i-1,j,move+'U',ans);
        m[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        solve(m,n,0,0,"",ans);
        return ans;
    }


};
