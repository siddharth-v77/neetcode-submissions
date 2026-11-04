#include<cstring>
class Solution {
public:
int t[202][202] ;
int solve(vector<vector<int>>& matrix , int i  , int j , int n , int m ){
    if(i >= n || j >= m || i < 0 || j < 0){
        return 0 ;
    }

    if(t[i][j] != -1){
        return t[i][j];
    }
int right = 0, left = 0, up = 0, down = 0;


    if( j+1 < m &&  matrix[i][j] < matrix[i][j+1]){
    right = solve(matrix, i, j+1, n, m);

    }
     if( j-1 >= 0 &&  matrix[i][j] < matrix[i][j-1]){
     left =  solve(matrix , i , j-1 ,n , m) ;

    }

    if( i-1 >= 0 && matrix[i][j] < matrix[i-1][j]){
         up =  solve(matrix , i-1 , j ,n ,m ) ;

    }

    if( i + 1 < n && matrix[i][j] < matrix[i+1][j]){
         down =  solve(matrix , i+1 , j , n , m) ;

    }

return t[i][j] = 1 + max({right , left , up , down});
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();
memset(t , -1 , sizeof(t));
        int ans = 0 ;
         for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                ans = max(ans , solve(matrix , i, j , n ,m ));
            }
         }
         return ans;
    }
};