class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        int prefixSum[sz+1];
        prefixSum[0] = 0;

        // Calculate the prefix sum of nums.
        for(int i = 1; i <= sz; i++){
            prefixSum[i] = nums[i-1] + prefixSum[i - 1];
        }
        // Check if at any position the sum of both side is equal
        // Left side sum = prefixSum[position]
        // Right Side sum = Total Sum - prefixSum[position + 1]
        int output = -1;
        for(int i = 0; i < sz; i++){
            if(prefixSum[i] == prefixSum[sz] - prefixSum[i + 1]){
                output = i;
                break;
            }
        }

        return output;
    }
};