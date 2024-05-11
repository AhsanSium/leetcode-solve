class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = 1;
            }
            else{
                mp[arr[i]]++;
            }
        }
        unordered_set <int> freq;
        for(auto i = mp.begin(); i != mp.end(); i++){
            if(freq.count(i->second) != 0) return false;
            freq.insert(i->second);
        }
        return true;
    }
};