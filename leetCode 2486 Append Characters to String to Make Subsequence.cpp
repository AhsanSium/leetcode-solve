class Solution {
public:
    int appendCharacters(string s, string t) {
        int p1 = 0, p2 = 0;
        int sz2 = s.size(), sz1 = t.size();
        string match = "";
        while(p1 < sz1 && p2 < sz2){
            if(t[p1] == s[p2]){
                match += t[p1];
                p1++;
                p2++;
            }
            else{
                p2++;
            }
        }
        
        int unmatched = 0;
        int p3 = 0, p4 = 0;
        while(p3 < sz1){
            if(match[p4] == t[p3]){
                p3++;
                p4++;
            }
            else{
                unmatched ++;
                p3++;
            }
        }

        return unmatched;
    }
};