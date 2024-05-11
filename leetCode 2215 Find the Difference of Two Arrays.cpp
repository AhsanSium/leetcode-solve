class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Create two map for tow number arrays
        map <int, int> mp1;
        map <int, int> mp2;
        vector<vector<int>> ans;
        // Add numbers to the map as key for separate maps
        for(int i = 0; i < nums1.size(); i++){
            mp1[nums1[i]] = i;
        }
        for(int i = 0; i < nums2.size(); i++){
            mp2[nums2[i]] = i;
        }
        vector <int> ans1, ans2;
        // Check if nums1 items not presented in map of nums 2, then pick those 
        // And set map2 that number to avoid repetitions
        for(int i = 0; i < nums1.size(); i++){
            if(mp2.find(nums1[i]) == mp2.end()){
                ans1.push_back(nums1[i]);
                mp2[nums1[i]] = i;
            }
        }
        for(int i = 0; i < nums2.size(); i++){
            if(mp1.find(nums2[i]) == mp1.end()){
                ans2.push_back(nums2[i]);
                mp1[nums2[i]] = i;
            }
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        
        return ans;
    }
};