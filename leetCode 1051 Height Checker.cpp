class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int sz = heights.size(), ans = 0;
        bool sorted = false;
        vector <int> cpy(heights);

        for(int i = 0; i < sz; i++){
            sorted = true;
            for(int j = 0; j < sz - i - 1; j++){
                if(heights[j] > heights[j+1]){
                    // bigger item found
                    swap(heights[j], heights[j + 1]);
                    sorted = false;
                }
            }
            if(sorted){ break;}
        }

        for(int i = 0; i < sz; i++){
            if(heights[i] != cpy[i]){ans ++;}
        }

        return ans;       
    }
};