// class Solution {
// public:

//         vector<vector<int>> ans;
//         vector<int> dir = {1,0,-1,0,1};
//     void dfs(int i , int j , int n, int m,vector<vector<int>>& heights, bool &pacific,bool &atlantic ,vector<vector<bool>> &vis){
//         if(vis[i][j] == true){
//             return ;
//         }

//         vis[i][j] = true;

//         if(i == 0 || j == 0){
//             pacific = true;
//         }

//         if(i == n-1 || j == m-1){
//             atlantic = true;
//         }

//         if(pacific && atlantic){
//             return;
//         }
//     for(int a = 0 ; a < 4 ; a++){
//         int i_new = i + dir[a];
//         int j_new = j + dir[a+1];

//         if( i_new >= 0 && j_new >= 0 && i_new < n && j_new < m && 
//         heights[i_new][j_new] <= heights[i][j]){
//             dfs(i_new,j_new , n , m ,heights , pacific , atlantic , vis);
//         }
//     }

//     }

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//        int n = heights.size();
//        int m = heights[0].size();

//     for(int i = 0 ; i < n ; i++){
//         for( int j =0 ; j < m ; j++){
// vector<vector<bool>> vis(n , vector<bool>(m,false));

//         bool pacific = false;
//         bool atlantic = false;
        
//             dfs(i , j , n, m , heights , pacific , atlantic , vis);

//             if( pacific && atlantic){
//                 ans.push_back({i,j});
//             }

//         }
//     }       
// return ans;
//     }
// };


class Solution {
public:

    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void DFS(vector<vector<int>>& heights,
             int i,
             int j,
             int prevHeight,
             vector<vector<bool>>& visited) {

        int m = heights.size();
        int n = heights[0].size();

        // Out of boundary
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;

        // Already visited
        if (visited[i][j])
            return;

        // Cannot move from previous cell to current cell
        if (heights[i][j] < prevHeight)
            return;

        visited[i][j] = true;

        // Explore all 4 directions
        for (auto& dir : directions) {

            int new_i = i + dir[0];
            int new_j = j + dir[1];

            DFS(heights,
                new_i,
                new_j,
                heights[i][j],
                visited);
        }
    }


    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        int m = heights.size();       // rows
        int n = heights[0].size();    // columns

        vector<vector<int>> result;

        vector<vector<bool>> pacificVisited(
            m, vector<bool>(n, false)
        );

        vector<vector<bool>> atlanticVisited(
            m, vector<bool>(n, false)
        );


        // --------------------------------
        // Top Row + Bottom Row
        // --------------------------------

        for (int j = 0; j < n; j++) {

            // Top row -> Pacific
            DFS(heights,
                0,
                j,
                INT_MIN,
                pacificVisited);

            // Bottom row -> Atlantic
            DFS(heights,
                m - 1,
                j,
                INT_MIN,
                atlanticVisited);
        }


        // --------------------------------
        // Left Column + Right Column
        // --------------------------------

        for (int i = 0; i < m; i++) {

            // Left column -> Pacific
            DFS(heights,
                i,
                0,
                INT_MIN,
                pacificVisited);

            // Right column -> Atlantic
            DFS(heights,
                i,
                n - 1,
                INT_MIN,
                atlanticVisited);
        }


        // --------------------------------
        // Find cells reachable by BOTH
        // --------------------------------

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (pacificVisited[i][j] &&
                    atlanticVisited[i][j]) {

                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};