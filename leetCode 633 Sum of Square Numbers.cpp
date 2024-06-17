class Solution {
public:
    bool judgeSquareSum(int c) {
        // int i = 1, mid = c / 2;
        // while(i <= c && i > 0){
        //     int eqn = i * i + (i+1 * i+1);
        //     if(eqn == c){
        //         return true;
        //     }
        //     else if(eqn > c){
        //         i--;
        //     }
        //     else{
        //         i++;
        //     }
        // }

        // for(long long i = 0; i <= sqrt(c); i++){
        //     for(long long j = 0; j <= sqrt(c); j++){
        //         /* 
        //         a^2 + b^2  Integer overflow
        //         We try use
        //         a^2 + b^2 = (a - b)^2 + 2ab also TLE
        //         */
        //         long long eqn = pow((i - j), 2) + 2*i*j;
        //         if(eqn == c){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // for (int divisor = 2; divisor * divisor <= c; divisor++) {
        //     if (c % divisor == 0) {
        //         int exponentCount = 0;
        //         while (c % divisor == 0) {
        //             exponentCount++;
        //             c /= divisor;
        //         }
        //         if (divisor % 4 == 3 && exponentCount % 2 != 0) {
        //             return false;
        //         }
        //     }
        // }
        // return c % 4 != 3;

        unordered_set <long long> st;
        for(long long i = 0; i <= sqrt(c); i++){
            st.insert(i*i);
        }


        long long i = 0;
        while(i*i <= c){
            long long target = c - (i*i);
            if(st.find(target) != st.end()){
                return true;
            }
            i++;
        }
        return false;
    }
};