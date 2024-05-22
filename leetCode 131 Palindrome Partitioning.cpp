class Solution {
public:
    vector <vector <string>> res;
    vector <string> part;
    int len;

    bool is_palindrome(string s, int i, int j)
    {
        while(i <= j){
            if(s[i] != s[j]){return false;}
            i++; j--;
        }
        return true;
    }

    void dfs(int idx, string s)
    {
        // define base case
        if(idx >= len){
            res.push_back(part);
        }

        // Iterate over every character of string from i to end and check
        for(int j = idx; j < len; j++){
            if(is_palindrome(s, idx, j)){
                string sub_str = "";
                for(int k = idx; k <= j; k++){
                    sub_str = sub_str + s[k];
                }
                part.push_back(sub_str);
                // Do phase of backtracking
                dfs(j+1, s);
                // Undo Phase of backtracking
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        len = s.size();
        dfs(0, s);
        return res;
    }
};