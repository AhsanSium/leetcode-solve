// Solution 1 -> O(n lon n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return t == s;
    }
};


// Solution 2 -> O (S + T)

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){return false;}

        unordered_map <char, int> mp1, mp2;
        for(int i = 0; i < s.size(); i++){
            if(mp1.find(s[i]) == mp1.end()){
                mp1[s[i]] = 1;
            }
            else{
                mp1[s[i]] ++;
            }
        }

        for(int i = 0; i < t.size(); i++){
            if(mp2.find(t[i]) == mp2.end()){
                mp2[t[i]] = 1;
            }
            else{
                mp2[t[i]] ++;
            }
        }

        // Iterate
        char key;
        for (const pair<char, int>& single : mp1)
        {
            key = single.first;
            // cout << " " << key << "\n";
            if(mp2.find(key) == mp2.end()){
                return false;
            }
            else if(mp1[key] != mp2[key]){
                return false;
            }
        }

        return true;
    }
};

