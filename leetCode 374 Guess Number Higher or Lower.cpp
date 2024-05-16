/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        int mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            int num = guess(mid);
            // cout << mid << " " << num << "\n";
            if(num == 0){ 
                return mid;
            }
            else if(num == -1){
                r = mid - 1;
            }
            else if(num == 1){
                l = mid + 1;
            }
        }
        return 0;
    }
};