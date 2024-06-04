class Solution {
public:
    int longestPalindrome(string s) {
        map <char, int> mp;
        int sz = s.size();
        // Counting all the characters in a map
        for(int i = 0; i < sz; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = 1;
            }
            else{
                mp[s[i]] += 1;
            }
        }
        // Handle corner case
        if(mp.size() == 1){
            return(mp.begin()->second);
        }
        int len = 0, count_one = 0;
        for(auto i : mp){
            
            // One element can have 1 times or odd times
            if(i.second % 2 != 0 && count_one != 1){count_one = 1;}
            
            // Other element can have even time only so remove 1 from odd ones
            if(i.second % 2 == 0){
                len += i.second;
            }
            else{
                len += (i.second - 1);
            }
        }
        return len + count_one;

    }
};