class Solution {
public:
    void reverse_str(string& str)
    {
        int n = str.length();
    
        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
    string removeStars(string s) {
        stack <char> st;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*'){ st.push(s[i]);}
            else{ st.pop();}
        }
        while(!st.empty()){
            // cout << st.top() << "\n";
            ans.push_back(st.top());
            st.pop();
        }
        reverse_str(ans);
        return ans;
    }
};