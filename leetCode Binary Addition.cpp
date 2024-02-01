class Solution {
public:
    long long int binaryToDecimal(string a){
        long long int ans = 0;
        int j = 0;
        for(int i = a.length() - 1; i >= 0; i--){
            ans = ans + pow(2, j) * (a[i] - '0');
            //cout << ans << "  ";
            j ++;
        }
        //cout << ans << "  \n";
        return ans;
    }

    string decimalToBinary(int a){
        if( a == 0) return "0";
        if(a == 1) return "1";
        string ans1 = "";
        string ans2 = "";
        int temp = 0;
        while(a > 0){
            temp = a % 2;
            ans1 = ans1 + to_string(temp);
            a = a / 2;
        }
        for(int i = ans1.length() - 1; i >= 0; i--){
            ans2 = ans2 + ans1[i];
        }
        return ans2;
    }

    string addBinary(string a, string b) {
        
        string ans = "";
        long long int dec1 = binaryToDecimal(a);
        long long int dec2 = binaryToDecimal(b);

        //cout << "Dec 1 & 2 " << dec1 << " " << dec2 << "\n";

        ans = decimalToBinary( dec1 + dec2 );

        return ans;
    }
};












string addBinary(string a, string b) {
        
        
        if(b.size() > a.size()) swap(a,b);
        
        
        while(b.size() < a.size()) b = "0" + b;

        int carry = 0;

        string res = "";

        for(int i = b.size()-1; i >= 0 ; --i)
        {
             
             if(b[i] == '1' && a[i]=='1')
             {

                if(carry == 0) res = "0" + res;
                
                else res = "1" + res;
                    
                carry = 1;
             }

             else if(b[i] =='0' && a[i] =='0')
             {

                if(carry == 0) res = "0" + res;
                 
                else
                {
                    res = "1" + res;
                    carry = 0;
                }
             }

             else if((b[i]=='0' && a[i]=='1') || (b[i]=='1' && a[i] == '0'))
             {
                 
                if(carry == 0) res = "1" + res;
                 
                else res = "0" + res;
                 
             }
             
        }
        
        if(carry == 1) res = "1" + res;
        
        return res;
    }
};








