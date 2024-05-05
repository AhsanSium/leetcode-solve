class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int cnt = 0;
        
        // Consider edge cases, size = 1 & 2
        if(sz == 1){
            if(flowerbed[0] == 0){cnt++;}
        }
        else if(sz == 2){
            if(flowerbed[0] == 0 && flowerbed[1] == 0){cnt++;}
        }

        // Check before and after items to determine flower space
        for(int i = 1; i < sz - 1; i++){
            cout << "I: " << i << " \n";
            if(i == 1 && (flowerbed[0] == 0 && flowerbed[1] == 0)){
                flowerbed[0] = 1;
                cnt++;
                // i++;
            }
            if(flowerbed[i - 1] + flowerbed[i] + flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                cnt++;
                // i++;
            }
            if(flowerbed[sz - 1] == 0 && flowerbed[sz - 2] == 0){
                flowerbed[sz - 1] = 1;
                cnt++;
                // i++;
            }
        }
        
        cout << cnt << "\n";
        if(cnt >= n){return true;}
        return false;
    }
};