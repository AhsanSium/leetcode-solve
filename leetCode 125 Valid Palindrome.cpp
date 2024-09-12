# 1. Naieve Solution

class Solution {
public:
    bool isPalindrome(string s) {
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){ 
                s.erase(s.begin() + i);
                i--;
             }
            else if((int)s[i] >= 48 && (int)s[i] <= 57){
                continue;
            }
            else if((int)s[i] >= 65 && (int)s[i] <= 90){
                s[i] = char((int)s[i] + 32);
            }
            else if((int)s[i] >= 97 && (int)s[i] <= 122){
                continue;
            }
            else{
                s.erase(s.begin() + i);
                i--;
            }
        }
        
        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[s.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
};