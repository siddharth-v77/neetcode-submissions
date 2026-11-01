#include<cstring>
class Solution {
public:
unordered_map<string,int> t ;
int solve(vector<int>& nums, int target , int reach , int i){
   if (i == nums.size()) {
            return (reach == target);
        } 

string key = to_string(i) + "," + to_string(reach);

        if (t.find(key) != t.end()) {
            return t[key];
        }

    int plus = solve(nums , target , reach + nums[i] , i+1);

    int sub = solve(nums ,target , reach - nums[i] , i+1);

    return t[key] = plus + sub ;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int reach = 0 ;
        return solve(nums , target , reach , 0);
    }
};