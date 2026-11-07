#include<cstring>
class Solution {
public:
int t[501][501];
int solve(string &s1, string &s2 , int i ,  int j){
    if(j == s2.length()){
        return s1.length() - i;
    }

if(t[i][j] != -1 ){
    return t[i][j] ;
}
 else if(i == s1.length()){
        return s2.length() - j;
    }

    if(s1[i] == s2[j]){
       return t[i][j] = solve(s1 , s2  , i+1 , j+1);
        
    }
    else {int insert = 1+ solve(s1 , s2 , i , j+1) ;
    int del  = 1+ solve(s1 , s2 , i+1 , j) ;
    int replace = 1+ solve(s1 ,s2 , i+1 , j+1);
    return t[i][j] = min({insert ,del , replace});
    }

    return -1 ;
}
    int minDistance(string word1, string word2) {
        memset(t , -1 ,sizeof(t));
        int n = word1.length();
        int m = word2.length();
int count = 0 ;

        return solve(word1 , word2 , 0 ,  0  );
    }
};