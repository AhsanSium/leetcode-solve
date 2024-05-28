class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        vector <int> dist;
        for(int i = 0; i < len; i++){
            dist.push_back(abs(s[i] - t[i]));
        }
        int cur_cost = 0, total = 0 ,left = 0, right = 0;
        while(right < len){
            cur_cost += dist[right];

            while(cur_cost > maxCost){
                cur_cost -= dist[left];
                left++;
            }
            total = max(total, right - left + 1);
            right++;
        }

        return total;
    }
};