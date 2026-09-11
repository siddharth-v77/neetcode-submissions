class Solution {
public:

bool ispalin(string s){
    string s2 = s;
    reverse(s2.begin(),s2.end());
    return s2 == s;
}

void getpart(string s,vector<string> &part ,vector<vector<string>> &ans){
if(s.size() == 0){
    ans.push_back(part);
    return ;
}
    for(int i = 0 ; i<s.size() ;i++){
       string subs = s.substr(0,i+1); 
        if(ispalin(subs)){
            part.push_back(subs);
            getpart(s.substr(i+1),part, ans);

            part.pop_back();
        }
    }
}

    vector<vector<string>> partition(string s) {
        vector<string> part;
        vector<vector<string>> ans;
        getpart(s , part , ans); 
        return ans;
    }
};
