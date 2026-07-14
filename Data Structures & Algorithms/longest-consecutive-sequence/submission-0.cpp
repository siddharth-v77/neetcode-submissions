class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        sort(nums.begin() ,nums.end());
        int n = nums.size();
        int count = 1;
        int maxi = 1;
        if(nums.empty())
    return 0;
    for(int i=0; i<n-1; i++){
        if( nums[i] == nums[i+1]){
            continue ;
        }

        if(nums[i] == nums[i+1]-1){
            count++ ;
        }

        else{maxi = max(count, maxi);
        count = 1;}
        
    }
    maxi = max(count, maxi);

    return maxi ;
    }
};