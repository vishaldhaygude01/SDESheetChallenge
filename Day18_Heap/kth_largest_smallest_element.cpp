vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
    int kthLargest = 0;
    int kthSmallest = 0;
    priority_queue<int>pqmax;
    priority_queue<int,vector<int>,greater<int>>pqmin;
    vector<int>ans(2);
    
    for(int i=0;i<n;i++){
        pqmax.push(arr[i]);
        if(pqmax.size() > k){
            pqmax.pop();
        }
    }
    ans[0] = pqmax.top();
    
    for(int i=0;i<n;i++){
        pqmin.push(arr[i]);
        if(pqmin.size() > k){
            pqmin.pop();
        }
    }
    ans[1] = pqmin.top();
    return ans;

}