class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& ans){
    
        
        if( i == nums.size()){
            ans.push_back(curr);
            
            return;
        }
        
        
        curr.push_back(nums[i]);
        solve(nums,i+1,curr,ans);
        curr.pop_back();
        
        int idx = i+1 ;
        while( idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        solve(nums,idx,curr,ans);
    
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(nums,0,curr,ans);
        return ans;
    }
};