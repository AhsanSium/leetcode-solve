class Solution {
public:
    bool is_palindrome(string str){
        // Base case
        if(str == "" || str.size() == 1){return true;}

        int sz = str.size();
        string sub_string = str.substr(1, sz - 2);

        return (str[0] == str.back()) && is_palindrome(sub_string);
    }
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            if(is_palindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};