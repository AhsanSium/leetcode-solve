class Solution {
public:
    int specialArray(vector<int>& nums) {
        int ans = -1, cnt = 0;
        // Loop check from 0 to size to check how many nums >= to that.
        // Count those numbers if the count == num then return ans 
        for(int i = 0; i <= nums.size(); i++){
            cnt = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] >= i){cnt++;}
            }
            if(cnt == i){ans = i; break;}
        }
        return ans;
    }
};