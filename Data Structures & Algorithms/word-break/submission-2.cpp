#include<cstring>

class Solution {
public:
int t[301] ; 
unordered_set<string> st;
bool solve( int idx , string &s, vector<string>& dict ){
    if(idx >= s.length() ){
        return true;
    }
if(t[idx] != -1){
    return t[idx] ; 
}

    if(st.find(s) != st.end()){
        return true;
    }

    for(int i = 1 ; i <= s.length() ; i++){
        string temp = s.substr(idx , i);

        if(st.find(temp) != st.end() && solve(idx+i , s , dict)){
            return t[idx] = true;
        }
    }
    return t[idx] = false;
}
    bool wordBreak(string s, vector<string>& dict) {

        memset( t , -1 , sizeof(t));

        int n = s.length();
        for(string &word : dict){
            st.insert(word) ;
        }

     return solve( 0 , s , dict);   
    }
};