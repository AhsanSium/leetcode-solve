class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector < pair <int, int> > v;
        int d_sz = difficulty.size();
        for(int i = 0; i < d_sz; i++){
            v.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(v.begin(), v.end());
        // sort(worker.begin(), worker.end());

        // for (int i = 0; i < d_sz; i++)
        // {
        //     cout << v[i].first << " "
        //         << v[i].second << endl;
        // }

        int i = 0, maxProfit = 0, tmp = 0;
        while(i < worker.size()){
            tmp = 0;
            for(int j = 0; j < d_sz && v[j].first <= worker[i]; j++){
                // cout << v[j].first << " " << worker[i] << " \n";
                tmp = max(tmp, v[j].second);
            }
            // cout << tmp << " \n";
            maxProfit += tmp;
            i++;
        }

        return maxProfit;
    }
};