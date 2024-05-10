class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // priority_queue < pair < double, pair <int, int> > > pq;
        map <double, vector<int>> mp;
        // vector <int> ans;
        vector <double> fractions;
        for(int i = 0; i < arr.size(); i++){
            for(int j = arr.size() - 1; j > i; j --){
                double fraction = (double)arr[i] / arr[j];
                // cout << arr[i] << arr[j] << fraction << "\n";
                // pair tmp (-1 * fraction, pair(arr[i], arr[j]));
                // pq.push(tmp);
                vector <int> temp {arr[i], arr[j]}; 
                fractions.push_back(fraction);
                mp[fraction] = temp;
            }
        }
        sort(fractions.begin(), fractions.end());

        return mp[fractions[k - 1]];
    }
};