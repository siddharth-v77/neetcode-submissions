class Solution {
public:

    vector<vector<int>> result;

    vector<vector<int>> solve(vector<int>& nums ,int i, vector<int>& temp) {
        if(i >= nums.size()){
            result.push_back(temp);
            return result;
        }
    temp.push_back(nums[i]);
    solve(nums,i+1,temp);
    temp.pop_back();
    solve(nums,i+1,temp);

return result;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        return solve(nums,0, temp);
    }
};