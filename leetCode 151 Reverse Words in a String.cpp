class Solution {
public:
    string reverseWords(string s) {
        vector <string> words;
        string temp = ""; 
        int sz = s.size();
        for(int i = 0; i < sz; i++){
            if(s[i] != ' '){
                temp = temp + s[i];
            }
            else if(temp.size() > 0 && s[i] == ' '){
                words.push_back(temp);
                temp = "";
            }
            
            if(i == sz - 1 && temp.size() > 0){
                // cout << s[i] << "\n";
                words.push_back(temp);
                temp = "";
            }
        }
        string ans = "";
        for(int i = words.size() - 1; i >= 0; i--){
            string word = words[i];
            ans = ans + words[i];
            if(i != 0){ans = ans + " ";}
        }
        return ans;
    }
};