class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int sz = people.size();
        sort(people.begin(), people.end());
        int cnt = 0;
        int sum = 0; int i_last = 0;
        int l = 0, r = sz - 1;
        while(r>=l){
            if(people[r] + people[l] <= limit){
                l++;
                r--;
                cnt++;
            }
            else{
                r--;
                cnt++;
            }
            
        }
        return cnt;
    }
};