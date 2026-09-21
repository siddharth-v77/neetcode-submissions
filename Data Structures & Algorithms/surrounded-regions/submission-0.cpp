class Solution {
public:
    vector<int> dir = {1,0,-1,0,1};
    void bfs(int i , int j , int n , int m ,vector<vector<char>>& board , vector<vector<bool>> &vis,
    vector<pair<int,int>> &component , bool& boundry){
        
        queue<pair<int,int>> q ;
        q.push({i,j});

        vis[i][j]=true;


        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            component.push_back({i,j});
            
            if(i == 0 || j == 0 || i == n-1 || j == m-1  ){
                boundry = true;
                
            }

            for(int a = 0 ; a < 4 ; a++){
             int i_ = i + dir[a] ;
             int j_ = j + dir[a+1];

             if(i_ >= 0 && j_ >= 0 && i_ < n && j_ < m && board[i_][j_] == 'O'&& !vis[i_][j_] ){
                vis[i_][j_] = true;
                q.push({i_,j_});
             }
        }

        }


    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

    
        

        for(int i = 0 ; i < n ;  i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    vector<pair<int,int>> component;
                    
                    bool boundry = false;
                     bfs(i ,j , n,m , board,vis , component , boundry);

                     if(!boundry){
                        for(auto cell : component){
                            int x = cell.first;
                            int y = cell.second;

                            board[x][y] = 'X';
                        }
                     }
                }
            }
        } 

        
    }
};