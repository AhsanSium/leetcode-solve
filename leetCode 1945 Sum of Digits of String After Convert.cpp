class Solution {
public:
    int getLucky(string s, int k) {
        string tmp = "";
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++){
            tmp = tmp + to_string((int)(s[i]) - 96);
        }
        cout << tmp << "\n";
        for(int i = 0; i < k; i++){
            ans = 0;
            for(int j = 0; j < tmp.size(); j++){
                cout << tmp[j] - '0' << " ";
                ans = ans + (tmp[j] - '0');
            }
            tmp = to_string(ans);
        }
        
        return ans;
    }
};