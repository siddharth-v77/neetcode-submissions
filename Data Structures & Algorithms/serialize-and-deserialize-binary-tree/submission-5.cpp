/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (root == NULL) {
            return "X";
        }

        string left = serialize(root->left);
        string right = serialize(root->right);

        string data = to_string(root->val) + "," + left + "," + right;

        return data;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> vec;
        string temp;

        for (char ch : data) {

            if (ch == ',') {
                vec.push_back(temp);
                temp.clear();
            }
            else {
                temp += ch;
            }
        }

        // Last value
        vec.push_back(temp);

        int i = 0;

        return build(vec, i);
    }


    TreeNode* build(vector<string>& vec, int& i) {

        if (i >= vec.size() || vec[i] == "X") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(vec[i]));
        i++;

        root->left = build(vec, i);
        root->right = build(vec, i);

        return root;
    }
};