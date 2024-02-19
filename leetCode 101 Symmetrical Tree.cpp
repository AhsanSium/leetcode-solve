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
    vector <int> ans = {};

    vector <int> dfs(TreeNode* a, bool dir){
        // Base Case
        if(a == NULL){
            if(dir == 1){ans.push_back(-100000);}
            else{ans.push_back(-200000);}
            return ans;
        }

        ans.push_back(a->val);
        dfs(a->left, 1);
        //cout << a->val <<" ";
        dfs(a->right, 0);

        //cout<<"  nl \n";
        return ans;
    }

    vector <int> dfs2(TreeNode* a, bool dir){
        // Base Case
        if(a == NULL){
            if(dir == 1){ans.push_back(-100000);}
            else{ans.push_back(-200000);}
            return ans;
        }

        ans.push_back(a->val);
        //cout << a->val <<" ";
        dfs2(a->right, 0);

        dfs2(a->left, 1);

        //cout<<"  nl \n";
        return ans;
    }

    bool isSymmetric(TreeNode* root) {

        if(root->left == NULL && root->right == NULL){
            return true;
        }
        
        vector <int> first = dfs(root->left, 1);
        ans.clear();
        vector <int> second = dfs2(root->right, 1);

        for(int i = 0; i < second.size(); i++){
            if(second[i] == -100000){second[i] = -200000;}
            else if(second[i] == -200000){second[i] = -100000;}
        }

        // for(int i = 0; i < first.size(); i++){
        //     cout << first[i] << " ";
        // }
        // cout << "\n";

        // for(int i = 0; i < second.size(); i++){
        //     cout << second[i] << " ";
        // }
        // cout << "\n";

        // reverse(second.begin(), second.end());

        if(first == second){return true;}
        else{return false;}
    }
};