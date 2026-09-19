class Solution {
public:
const int INF = 2147483647;
  vector<int> dir = {0,1,0,-1,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

    queue<pair<int,int>> q;

    for(int i = 0 ;i < n ; i++){
        for(int j =0 ; j < m ; j++){

            if(grid[i][j] == 0){
                q.push({i,j});
            }
        }
    }

  

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;

        q.pop();
        for(int a = 0 ; a<4 ; a++){
            int i_new = i +dir[a];
            int j_new = j +dir[a+1];

            if( i_new >=0 && i_new < n && j_new >=0 && j_new < m 
                && grid[i_new][j_new] == INF)
                {
                grid[i_new][j_new] = grid[i][j] +1;
                 q.push({i_new, j_new});

            }

        }
    }

    }
};
