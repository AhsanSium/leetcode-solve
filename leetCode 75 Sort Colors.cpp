class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            bool sorted = true;
            for(int j = 0; j < sz - i - 1; j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j + 1]);
                    sorted = false;
                }
            }
            if(sorted){break;}
        }
    }
};