class Solution {
public:

    // // O N^2
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for(int i = 0; i < nums.size(); i++){
    //         for(int j = 0; j < nums.size(); j++){
    //             if(i != j && nums[i] + nums[j] == target){
    //                 return vector <int> {i,j};
    //             }
    //         }
    //     }
    //     return vector <int> {0, 0};
    // }

    // O (n log n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return vector <int> { i, mp[target - nums[i]]};
            }
            else{
                mp[nums[i]] = i;
            } 
        }
        return vector <int> {0, 0};
    }
};