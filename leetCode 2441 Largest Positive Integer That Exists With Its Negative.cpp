class Solution {
public:
    // Two pointer approach: O(n log n)
    int findMaxK(vector<int>& nums) {
        int ans = -1, sz = nums.size();
        int l = 0, r = sz - 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < sz; i++)
            cout << nums[i] << ' ';
        
        while(r > l){
            // cout << l << r << " .";
            if(nums[r] == (-1 * nums[l])){
                ans = nums[r];
                return ans;
            }
            else if(-1 * nums[l] > nums[r]){l++;}
            else{r--;}
        }
        return ans;
    }
};