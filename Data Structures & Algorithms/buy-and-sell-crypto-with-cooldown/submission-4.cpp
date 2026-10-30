#include<cstring>
class Solution {
public:
int t[5001][2];
int solve(vector<int>& prices , int i , int n , bool buy){
    if(i >= n ){
        return 0;
    }
    if(t[i][buy] != -1 ){
return t[i][buy];
    }
int profit= 0;
    if(buy){
        int take = solve(prices , i+1 ,n , false) - prices[i]; //buy then sell ker rhe pan

        int nottake = solve(prices , i+1 , n , true) ; // yha aaj nahi kharighe kal ya bad me kahridemge

        profit = max({profit , take  , nottake});
    }

    else{
        int sell = prices[i] + solve(prices , i+2 , n ,true) ; //uha bech diya or phit bad me kjridene ke liye bol diay

        int notsell = solve(prices , i+1 , n , false); // nahi bad me bechenge

        profit = max({profit , sell ,notsell});
    }
    return t[i][buy] = profit;
}
    int maxProfit(vector<int>& prices) {
        memset(t ,-1 , sizeof(t));
        bool buy = true;
        int n = prices.size();
        return solve(prices , 0 , n , buy);
    }
};