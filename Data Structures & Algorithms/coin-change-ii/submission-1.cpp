#include<cstring>
class Solution {
public:
int t[5001][301];
int solve(vector<int>& coins , int amount , int i){
    if(amount == 0 ){
        return 1; 
    }
if(t[amount][i] != -1 ){
    return t[amount][i];
}
    if(i == coins.size()){
        return 0;
    }


    if( amount < coins[i]){
        return  t[amount][i] = solve(coins , amount , i+1);
    }

    int take = solve(coins , amount-coins[i] , i) ;

    int skip = solve(coins , amount , i+1);

    return t[amount][i] =  take + skip ;
}
    int change(int amount, vector<int>& coins) {

        memset( t , -1 , sizeof(t));
        return solve(coins , amount , 0);
    }
};
