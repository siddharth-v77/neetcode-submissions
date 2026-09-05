class Solution {
public:
void solve(vector<int>& arr, int tar, int i ,vector<int>&combi,vector<vector<int>>&ans ){
if(tar<0){
    return;
}

if(tar == 0){
    ans.push_back(combi);
    return ;
}
for(int a = i ; a<arr.size(); a++)
   { 
    if(a > i && arr[a] == arr[a-1]){
        continue;
    }
    combi.push_back(arr[a]);
    solve(arr , tar-arr[a], a+1 ,combi , ans);  //sigle time taking

    combi.pop_back();
}
}
    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        
        vector<int> combi;
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());   // important

        solve(arr, tar, 0, combi,ans);
        return ans;
    }
};