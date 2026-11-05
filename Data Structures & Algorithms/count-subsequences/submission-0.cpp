#include<cstring>  
class Solution {
public:
int p[1001][1001] ;
int solve(string& s, string& t , int i , int j ){
    if(j == t.length()){
        return 1;
    }
if( p[i][j] != -1){
    return p[i][j];
}
    if(i == s.length()){
        return 0; 
    }

    if(s[i] == t[j]){
        return p[i][j] = solve(s, t, i+1 , j+1) + solve(s , t , i+1 , j) ;
    } 
    else return p[i][j] = solve(s , t , i+1 , j) ;

    return -1;
}
    int numDistinct(string s, string t) {
        memset(p ,-1 , sizeof(p));
        return solve(s , t , 0 , 0 );
    }
};