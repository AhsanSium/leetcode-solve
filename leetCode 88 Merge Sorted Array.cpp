class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> ans;
        if(m == 0){
            nums1 = nums2;
            return;
        }
        if(n == 0){
            return;
        }
        int a1 = 0, b1 = 0;
        while(1){
            if(a1 < m && b1 < n && nums1[a1] <= nums2[b1]){
                ans.push_back(nums1[a1]);
                a1 ++;
            }
            else if(a1 < m && b1 < n && nums1[a1] > nums2[b1]){
                ans.push_back(nums2[b1]);
                b1 ++;
            }
            else{
                if(a1 == m && b1 < n){
                    ans.push_back(nums2[b1]);
                    b1 ++;
                }
                if(b1 == n && a1 < m){
                    ans.push_back(nums1[a1]);
                    a1 ++;
                }
            }

            if(a1 >= m && b1 >= n) break;
        }

        nums1 = ans;
    }
};