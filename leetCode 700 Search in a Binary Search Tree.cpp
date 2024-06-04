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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Handle base case
        if(root == NULL){return NULL;}
        cout << "Val: " << root->val << " \n";
        
        //Handle found
        if(root -> val == val){
            cout << "Value: "<< val << "\n";
            return root;
        }

        TreeNode* a = searchBST( root -> left, val);
        TreeNode* b = searchBST ( root -> right, val );
        if(a == NULL){return b;}
        else{return a;}
    }
};