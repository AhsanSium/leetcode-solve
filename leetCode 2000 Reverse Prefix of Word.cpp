class Solution {
public:
    string reversePrefix(string word, char ch) {
        int sz = word.size(), idx = -1;
        string rest = "";
        for(int i = 0; i < sz; i++){
            if(word[i] == ch && idx == -1){
                idx = i;
            }
            if(idx != -1 && i > idx){
                rest = rest + word[i];
            }
        }
        if(idx == -1){return word;}
        //cout << idx << rest << "\n";
        string ans = "";
        for(int i = idx; i > -1; i--){
            ans += word[i];
        }
        return (ans += rest);
    }
};
