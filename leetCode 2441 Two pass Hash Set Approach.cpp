class Solution {
public:
    // Two Pass Hash set Approach
    int findMaxK(vector<int>& nums) {
        // Initialize an unordered set to store negative numbers
        unordered_set<int> neg;
        
        // Loop through the numbers and insert negative numbers into the set
        for (int num : nums) {
            if (num < 0)
                neg.insert(num);
        }
        
        int ans = -1;
        
        for (int num : nums) {
            // If current number is greater than ans and its negation exists in the set
            if (num > ans && neg.contains(-num))
                ans = num;
        }
        
        return ans;
    }
};