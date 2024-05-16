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
    void right_dfs(TreeNode * p, int level, vector <int> &node){
        
        if(p == NULL){return;}
        if(node.size() == level)
            node.push_back(p->val);

        right_dfs(p->right, level + 1, node);
        right_dfs(p->left, level + 1, node);
    }

    void right_bfs(TreeNode * p, vector <int> & node){
        if(p == NULL){return;}
        queue <TreeNode *> q;
        q.push(p);
        node.push_back(p->val;)
        
        while (q.empty() == false) {
            // Print front of queue and remove it from queue
            TreeNode * node = q.front();
            cout << node->data << " ";
            q.pop();

            // Enqueue left child
            if (node->left != NULL)
                q.push(node->left);

            // Enqueue right child
            if (node->right != NULL)
                q.push(node->right);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector <int> ans;
        right_dfs(root,0,ans);
        return ans;
    }
};