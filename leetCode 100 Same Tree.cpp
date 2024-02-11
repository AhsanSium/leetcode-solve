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

    // Binary Direction, dir = 1 for left, 0 for right
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector <int> first = dfs(p, 1);
        ans.clear();
        vector <int> second = dfs(q, 1);

        // sort(first.begin(), first.end());
        // sort(second.begin(), second.end());
        
        // cout << " \n";
        // for(int i = 0; i < first.size(); i++){
        //     cout << first[i] << " ";
        // }
        // cout << " \n";
        // for(int i = 0; i < second.size(); i++){
        //     cout << second[i] << " ";
        // }
        // cout << " \n";

        if(first == second){return true;}
        else{return false;}

    }
};