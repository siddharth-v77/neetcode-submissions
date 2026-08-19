/**
 * Definition for a binary tree node.
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

    bool isidentical(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot == NULL){
            return root == subRoot;
        }
        bool left =  isidentical(root->left,subRoot->left);
        bool right =  isidentical(root->right,subRoot->right);

        return left && right && root->val==subRoot->val;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(root == NULL || subRoot == NULL){
            return root == subRoot;
        }
        
        if(root->val == subRoot->val && isidentical(root,subRoot)){
            return true;
        }
        bool lefthave =isSubtree(root->left, subRoot);
        bool righthave =isSubtree(root->right, subRoot);

        return lefthave || righthave;
    }
};
