class Solution {
public:
    vector <int> dec_to_bin(int num){
        //cout << num << "\n";
        vector <int> ans;
        int temp = 0;
        while(num > 0){
            temp = num % 2;
            ans.insert(ans.begin(), temp);
            num = num / 2;
            //cout << num << " num \n";
        }
        return ans;
    }
    int bin_to_dec(vector <int> bin){
        int ans = 0;
        reverse(bin.begin(), bin.end());
        for(int i = 0; i < bin.size(); i++){
            ans = ans + bin[i] * pow(2 , i);
        }
        return ans;
    }
    vector <int> a_xor_b(vector <int> a, vector <int> b) {
        vector <int> x_or;
        int sz1 = a.size(), sz2 = b.size();
        int sz = (sz1 > sz2) ? sz1 : sz2;
        if(sz > sz1){
            for(int i = sz1; i < sz; i++){
                a.insert(a.begin(), 0);
            }
        }
        else{
            for(int i = sz2; i < sz; i++){
                b.insert(a.begin(), 0);
            }
        }
        for(int i = 0; i < sz; i++){
            if(a[i] == b[i]){
                x_or.push_back(0);
            }
            else{
                x_or.push_back(1);
            }
        }
        return x_or;
    }
    int subsetXORSum(vector<int>& nums) {
        // vector <int> ans = dec_to_bin(294);
        // for(int i = 0; i < ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
        // cout << "\n";
        vector <int> binary {1, 1, 0, 1};
        // int dec = bin_to_dec(binary);
        // cout << dec << "\n";
        // vector <int> bin1 {0, 0, 1, 1};
        // vector <int> bin2 {0, 1, 0, 1};
        // vector <int> x_or = a_xor_b(bin1, bin2);
        // for(int i = 0; i < x_or.size(); i++){
        //     cout << x_or[i] << " ";
        // }
        // cout << "\n";
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            total = total + nums[i];
        }
        vector <int> tmp = dec_to_bin(nums[0]);
        

        return total;
    }
};



class Solution {
public:
    int len = 0;
    vector <int> numbers;
    int dfs(int i, int total){
        // Base case
        if (i == len){return total;}

        // include number[i]
        int total1 = dfs(i+1, total ^ numbers[i]);
        // not include number[i]
        int total2 = dfs(i+1, total);

        return total1 + total2; 
    }
    int subsetXORSum(vector<int>& nums) {
        len = nums.size();
        numbers = nums;
        return dfs(0, 0);
    }
};