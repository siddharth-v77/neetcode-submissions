#include<cstring>
class Solution {
public:
int dp[1002][1002];
bool solve(int i , int j , string &s){
    if(i >=j){
        return dp[i][j] = 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i] == s[j]){
        return dp[i][j] = solve(i+1,j-1 ,s);
    }

    return dp[i][j] = 0 ;
}
    int countSubstrings(string s) {
       memset(dp , -1 , sizeof(dp)) ;
        int n = s.length();
        int count =0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(solve(i , j, s)){
                    count++;
                }
            }
        }
        return count ;
    }
};