int LongestSubsetWithZeroSum(vector < int > A) {

  // Write your code here
    int n = A.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
        int curSum = 0;
        for(int j=i;j<n;j++){
            curSum += A[j];
            if(curSum == 0){
                maxLen = max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;

}