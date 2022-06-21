class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        
        int i = 0;
        int j = 0;
        int kth = 0;
        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                kth++;
                if(kth == k){
                   return arr1[i];
                }
                i++;
            }
            else{
                kth++;
                if(kth == k){
                    return arr2[j];
                }
                j++;
            }
        }
        while( i<n){
            kth++;
               if(kth == k)
               {
                   return arr1[i];
               }
               i++;
           
        }
        while( j<m){
            kth++;
                if(kth == k){
                    return arr2[j];
                }
                j++;
        }
        return -1;
    }
};

/*
        priority_queue<int, vector<int>,greater<int>>pq;
        for( int i=0; i<n;i++){
            pq.push(arr1[i]);
        }
        for( int i=0; i<m;i++){
            pq.push(arr2[i]);
        }
        while(k-->1){
            pq.pop();
        }
        return pq.top();
        
*/

/*
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(arr1[i]);
        }
        for(int j=0;j<m;j++){
            ans.push_back(arr2[j]);
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
*/
