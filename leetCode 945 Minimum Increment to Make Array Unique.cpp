class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        // Corner case
        int sz = nums.size();
        if(sz == 1){return ans;}

        // Two pointer technique
        int i = 0, j = 1;
        while(j < sz){
            if(nums[i] < nums[j]){
                i++; j++;
            }
            else if(nums[i] == nums[j]){
                nums[j] += 1;
                ans ++;
                i++; j++;
            }
            else{
                // nums[i] > nums[j]
                int tmp = nums[i] - nums[j];
                nums[j] += tmp + 1;
                ans += tmp + 1;
                i++; j++;
            }
        }    
        return ans;
    }
};