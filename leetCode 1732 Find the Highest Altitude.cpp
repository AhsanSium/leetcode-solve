class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0, tmp = 0, prv = 0;
        int sz = gain.size();

        for(int i = 0; i < sz; i++){
            tmp = prv + gain[i];
            prv = tmp;
            // cout << tmp << "\n";
            mx = max(mx, tmp);
        }
        return mx;
    }
};
