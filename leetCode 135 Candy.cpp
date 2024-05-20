class Solution {
public:
    int candy(vector<int>& ratings) {
        vector < pair <int, int> > v;
        int sz = ratings.size();
        for(int i = 0; i < sz; i++){
            pair <int, int> tmp;
            tmp.first = ratings[i];
            tmp.second = i;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end());
        int total = 0;
        vector <int> candy(sz);
        // candy[v[0].second] = 1;
        for(int i = 0; i < sz; i++){
            int candy_l = 0, candy_r = 0;
            int idx = v[i].second;
            // cout << "IDX: " << idx << "\n";
            if(idx-1 >= 0 && ratings[idx] > ratings[idx - 1]){
                candy_l = candy[idx - 1] + 1;
            }
            if(idx + 1 < sz && ratings[idx] > ratings[idx + 1]){
                candy_r = candy[idx + 1] + 1;
            }

            if(candy_l == 0 && candy_r == 0){candy[idx] = 1;}
            else{candy[idx] = max(candy_l, candy_r);}
            
            // cout << "CandyL: " <<candy_l << "   CandyR: " << candy_r << "   candy:" << candy[idx] <<  "\n"; 
        }
        for(int i = 0; i < sz; i++){
            // cout << candy[i] << " ";
            total += candy[i];
        }
        // cout << "\n";

        return total;
    }
};