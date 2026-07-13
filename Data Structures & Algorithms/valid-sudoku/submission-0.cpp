class Solution {
public:
    bool check(int row, int col, vector<vector<char>> & board, int val){
        for(int j=0; j<9; j++){
            if ( board[row][j]-'0' == val && j!=col) return false;
        }

        for( int i =0; i<9; i++){
            if(board[i][col]-'0' == val && i!= row) return false;
        }

        int st_row= (row/3)*3;
        int st_col= (col/3)*3;
        for(int i=0;i<3;i++){
            for(int j =0;j<3;j++){
                int i_new=st_row+i;
                int j_new=st_col+j;
                if(board[i_new][j_new]-'0'==val && (i_new!=row || j_new!=col)) return false;

            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int val =board[i][j]-'0';
                    if(check(i,j,board,val)== false)return false;
                }
            }
        }
        return true;
    }
};