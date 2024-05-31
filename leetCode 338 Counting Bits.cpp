class Solution {
public:
    int no_of_ones(int n){
        int no = 0;
        while(n != 0){
            int temp = n % 2;
            n = n / 2;
            if(temp == 1){no++;}
        }
        return no;
    }
    vector<int> countBits(int n) {
        vector <int> bits;
        for(int i = 0; i <= n; i++){
            bits.push_back(no_of_ones(i));
        }
        return bits;
    }
};