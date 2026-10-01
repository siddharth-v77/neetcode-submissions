// class Solution {
// public:
//     int climbStairs(int n) {
        

//         if( n == 1 || n == 2  || n==3){
//             return n;
//         }

//         vector<int> t(n+1);
   
//         t[0] =0;
//         t[1] = 1;
//         t[2] =2;

//         for(int i =3 ; i <= n ; i++){
//             t[i] = t[i-1]+t[i-2];
//         }
//         return t[n];
//     }
// };


#include <cstring>
class Solution {
public:
int t[46];
int solve(int n){
    if(n < 0){
        return 0;
    }

    if(t[n] != -1){
        return t[n];
    }

    if(n == 0){
        return 1;
    }

    int jump1 = solve(n-1);
    int jump2 = solve(n-2);

    return t[n] = jump1+jump2 ;
}
    int climbStairs(int n) {
        memset(t, -1 , sizeof(t)) ;
        return solve(n);
    }
};


