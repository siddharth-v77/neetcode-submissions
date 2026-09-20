class Solution {
public:

        vector<vector<int>> ans;
        vector<int> dir = {1,0,-1,0,1};
    void dfs(int i , int j , int n, int m,vector<vector<int>>& heights, bool &pacific,bool &atlantic ,vector<vector<bool>> &vis){
        if(vis[i][j] == true){
            return ;
        }

        vis[i][j] = true;

        if(i == 0 || j == 0){
            pacific = true;
        }

        if(i == n-1 || j == m-1){
            atlantic = true;
        }

        if(pacific && atlantic){
            return;
        }
    for(int a = 0 ; a < 4 ; a++){
        int i_new = i + dir[a];
        int j_new = j + dir[a+1];

        if( i_new >= 0 && j_new >= 0 && i_new < n && j_new < m && 
        heights[i_new][j_new] <= heights[i][j]){
            dfs(i_new,j_new , n , m ,heights , pacific , atlantic , vis);
        }
    }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int n = heights.size();
       int m = heights[0].size();

    for(int i = 0 ; i < n ; i++){
        for( int j =0 ; j < m ; j++){
vector<vector<bool>> vis(n , vector<bool>(m,false));

        bool pacific = false;
        bool atlantic = false;
        
            dfs(i , j , n, m , heights , pacific , atlantic , vis);

            if( pacific && atlantic){
                ans.push_back({i,j});
            }

        }
    }       
return ans;
    }
};