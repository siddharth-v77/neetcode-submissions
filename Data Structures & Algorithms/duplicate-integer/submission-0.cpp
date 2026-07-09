class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for ( int num : nums)  st.insert(num);
        if( st.size() == nums.size()){
            return false ;
        }
        return true; 
    }
};