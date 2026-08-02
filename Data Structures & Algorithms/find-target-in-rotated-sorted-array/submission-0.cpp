class Solution {
public:
    int search(vector<int>& a, int tar) {
         int i =0;
         int j= a.size()-1;

         while(i<=j){
            int mid = i+ (j-i)/2;

            if (a[mid] == tar){
                return mid;
            }

            if(a[i] <= a[mid]){
                if(a[i] <= tar && tar<= a[mid]) j=mid-1;
                else i =mid+1;
            }

            else{
                if(a[mid]<=tar && tar<= a[j]) i = mid+1;
                else j= mid-1;
            }
         }
         return -1;
    }
};