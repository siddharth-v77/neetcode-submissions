class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , n = matrix[0].size();
        int mid=0;
        int row =0;
        int st_row =0, end_row = m-1;
        while(st_row <= end_row){
            mid = st_row + (end_row-st_row)/2;
            
            if(matrix[mid][0] <= target && target <= matrix[mid][n-1]){
                row = mid;
                break;
            }
            else if( matrix[mid][0] > target){ 
                end_row = mid-1;
            }

            else if( matrix[mid][n-1] < target){
                st_row = mid+1;
            }
            else return false;
        }
        int mid2=0;
        int st_col=0 , end_col = n-1;

        while(st_col<= end_col){
            mid2= st_col+ (end_col-st_col)/2;

              
            if(matrix[row][mid2] == target){
                return true;
            }
            else if( matrix[row][mid2] > target){
                end_col = mid2-1;
            }

            else if( matrix[row][mid2] < target){
                st_col = mid2+1;
            }
            else return false;
        }
        return false;
    }
};