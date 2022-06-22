/*

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
        if(array2.size() < array1.size()){
            return findMedianSortedArrays(array2,array1);
        }
        int n1 = array1.size();
        int n2 = array2.size();
        int start = 0;
        int end = n1;
        while(start <= end){
            int cut1 = (start+end)/2;
            int cut2 =(n1+n2+1) / 2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : array1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : array2[cut2-1];
            
            int r1 = cut1 == n1 ? INT_MAX : array1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : array2[cut2];
            
            if(l1 <= r2 && l2<= r1){
                if((n1 + n2) % 2 == 0){
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                }
                else{
                    return max(l1,l2);
                }
                
            }
            else if(l1 > l2){
                end = cut1 - 1;
            }
            else{
                start = cut1 + 1;
            }
        }
        return 0.0;
    }
};