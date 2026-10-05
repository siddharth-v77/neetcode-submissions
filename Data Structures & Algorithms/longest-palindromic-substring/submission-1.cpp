#include <cstring>
class Solution {
public:
int t[1001][1001];
bool checkpalin(int i , int j , string &s){
    if(i >=j){
        return t[i][j] =1;
    }
    if(t[i][j] != -1) return t[i][j];

    if(s[i] == s[j]){
        return t[i][j ]= checkpalin(i+1 , j-1 ,s) ;
    }
    return t[i][j] = 0;
}
    string longestPalindrome(string s) {
       memset(t,-1 , sizeof(t)) ;
        int n = s.length();
        int maxlen = INT_MIN;
        int sp = 0 ;

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j< n ; j++){
                if(checkpalin(i , j ,s)){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};