
#include<cstring>
class Solution {
public:
int t[101][101][201] ;
bool solve(string& s1, string &s2, string &s3 , int i , int j , int k){
    if( k == s3.length()){
        return true;
    }

    if(t[i][j][k] != -1 ){
        return t[i][j][k];
    }

if(s1[i] == s2[j] && s2[j] == s3[k]){
        return t[i][j][k] = solve(s1 , s2 ,s3 , i+1 , j , k+1) || solve(s1 ,s2 ,s3 ,i , j+1 ,k+1); ; 
    } 

 else  if(s1[i] == s3[k]){
        return t[i][j][k]= solve(s1 , s2 ,s3 , i+1 , j , k+1);
    }
    
    else if(s2[j] == s3[k]){
        return t[i][j][k] = solve(s1 ,s2 ,s3 ,i , j+1 ,k+1);
    }
    
    else return false;

    return true;
}
    bool isInterleave(string s1, string s2, string s3) {
        
        memset(t , -1 , sizeof(t));
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }

        return solve(s1 ,s2 ,s3 , 0 , 0 , 0);

    }
};