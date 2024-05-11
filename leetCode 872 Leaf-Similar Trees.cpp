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
    
    void dfs(TreeNode * p, vector<int> &tree){
        if(p != NULL && p->left == NULL && p->right == NULL){
            tree.push_back(p->val);
        }
        if(p == NULL){return;}
        dfs(p -> left, tree);
        dfs(p -> right, tree);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> tree1;
        vector <int> tree2;
        dfs(root1, tree1);
        dfs(root2, tree2);

        if(tree1 == tree2) return true;
        return false;
    }
};