#include<cstring>
class Solution {
public:
int t[21][21] ; 
bool solve(string s, string p , int i , int j ){
    if(j == p.length()){
        return i == s.length();
    }

    if(t[i][j] != -1 ){
        return t[i][j] ;
    }

    bool firstcheck = false;

    if( i < s.length() && (p[j] == s[i]  || p[j] == '.')){
        firstcheck = true;
    }

    if(p[j+1] == '*'){
        bool nottake = solve(s , p , i , j+2);
        bool take = firstcheck && solve(s , p , i+1 , j) ;

        return t[i][j] = nottake || take ;
    }

    return t[i][j] = firstcheck && solve(s , p , i+1 , j+1);
}
    bool isMatch(string s, string p) {
        memset(t , -1 , sizeof(t));
        return solve(s, p , 0 , 0) ;
    }
};