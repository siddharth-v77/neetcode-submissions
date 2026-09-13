class Solution {
public:
//horizontal
bool isSafe(vector<string> &b ,int raw ,int col , int n ){
    for(int j = 0 ; j<n ; j++){
        if(b[raw][j] == 'Q') return false;
    }

    //vertical

     for(int i = 0 ; i<n ; i++){
        if(b[i][col] == 'Q') return false;
    }

    //digonal left
    for(int i =raw ,j =col ;i>=0&&j>=0 ; i--,j--){
        if(b[i][j] == 'Q') return false;
    }

    //diginal right
    for(int i =raw ,j=col ;i >= 0 && j<n ; i--,j++){
        if(b[i][j] == 'Q') return false;
    }
return true;
}

void queen(vector<string> &b , int raw, int n ,  vector<vector<string>> &ans ){

    if(raw == n){
        ans.push_back({b});
        return ; 
    }


    for(int j =0 ;j<n ; j++){
        if(isSafe(b,raw, j,n)){
            b[raw][j] = 'Q';
            queen(b,raw+1,n,ans);
            b[raw][j] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
       vector<string>b(n, string(n , '.')) ;
       vector<vector<string>> ans;
       queen(b, 0 ,n ,ans);
       return ans;
    }
};