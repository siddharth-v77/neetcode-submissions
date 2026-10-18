class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi =  nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] < 0 ){
                swap(maxi , mini);
            }
             maxi = max(nums[i], maxi*nums[i]);
             mini = min(nums[i], mini * nums[i]);

             ans  = max(maxi , ans); 
        }
        return ans;
    }
};



// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//      int maxi = -10;
//      int n = nums.size();
//      for(int i = 0 ; i< n ; i++ ){
//         int product = 1;
//         for(int j = i ; j < n ; j++){
//              product *= nums[j];

//             maxi = max(maxi , product);
//         }
//      }   
//      return maxi;
//     }
// };