class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = k;
        int sz = nums.size();
        double sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        double mx = sum;
        while(r < sz){
            sum = sum - nums[l]; l++;
            sum = sum + nums[r]; r++;

            mx = max(mx, sum);
        }
        return (double)mx / k;
    }
};