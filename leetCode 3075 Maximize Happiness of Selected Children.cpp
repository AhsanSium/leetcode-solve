class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long sum = 0;
        int turn = 0;
        for(long long i = 0; i < k; i++){
            long long last = happiness.back();
            cout << last << "\n";
            happiness.pop_back();
            if(last >= 0) sum = sum + last;
            turn ++;
            if(!happiness.empty() && happiness.back() - 1 >= 0){
                happiness.back() = happiness.back() - turn;
            }
        }
        return sum;
    }
};