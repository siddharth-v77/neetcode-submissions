/**
 * Definition for a binary tree root.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int countgoodnodes(TreeNode* root , int max){
    if(root == NULL){
        return 0 ;
        }
int count = 0 ; 
        if(root->val >= max){
            count = 1;
            max=root->val  ;
        }

        count += countgoodnodes(root->left , max) ;
        count += countgoodnodes(root->right , max) ;

        return count;
    
}

    int goodNodes(TreeNode* root) {
        return countgoodnodes(root,INT_MIN ) ;
    }
} ;