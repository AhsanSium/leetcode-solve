class Solution {
public:
    string reverseVowels(string s) {
        int sz = s.size();
        int l = 0, r = sz - 1;
        string vowels = "aeiouAEIOU";
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(r > l){
            if(vowels.find(s[l]) != string::npos && vowels.find(s[r]) != string::npos ){
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                r --;
                l ++;
            }
            else if(vowels.find(s[l]) != string::npos){
                r --;
            }
            else{
                l ++;
            }
        }
        
        return s;
    }
};