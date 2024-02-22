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
    //int depth = 0;
    int dfs(TreeNode * p){
        if(p == NULL){return 0;}

        int dp1 = dfs(p->left);
        int dp2 = dfs(p->right);

        // cout << dp1 << " " << dp2 << "\n";

        if(dp1 >= dp2){return dp1 + 1;} 
        else { return dp2 + 1;}
    }
    int maxDepth(TreeNode* root) {
        int res = dfs(root);
        return res;
    }
};