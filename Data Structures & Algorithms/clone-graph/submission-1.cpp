/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

unordered_map<Node* , Node*> mp;

void dfs(Node* node, Node* curr_clone_node){
    for(Node* n : node->neighbors){
        if(mp.find(n) == mp.end()){
            Node* clone = new Node(n->val);
            mp[n] = clone;

            curr_clone_node->neighbors.push_back(clone);
            dfs(n ,clone);
        }
        else 
        curr_clone_node->neighbors.push_back(mp[n]);

    }
}

    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
mp.clear();
        Node* curr_clone_node = new Node(node->val);
        mp[node] = curr_clone_node;
        dfs(node, curr_clone_node);

        return curr_clone_node;
    }
};