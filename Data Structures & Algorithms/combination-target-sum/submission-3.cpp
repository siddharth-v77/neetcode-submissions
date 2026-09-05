class Solution {
public:
set<vector<int>> s ;
void solve(vector<int>& arr, int tar, int i ,vector<int>&combi,vector<vector<int>>&ans ){

if(tar< 0 || i == arr.size()){
    return;
}

if( tar == 0 ){

    if(s.find(combi) == s.end()){
        ans.push_back(combi);
        s.insert(combi);
    }

return;
    }
    combi.push_back(arr[i]);
    solve(arr , tar-arr[i], i+1 ,combi , ans);  //sigle time taking
    solve(arr , tar-arr[i], i ,combi , ans);  // multiple timing taling 

    combi.pop_back();
        solve(arr , tar, i+1 ,combi , ans);

}
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<int> combi;
        vector<vector<int>>ans;

        solve(arr, tar, 0, combi,ans);
        return ans;
    }
};