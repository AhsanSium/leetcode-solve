#include<bits/stdc++.h>
#include <map>
#include<string>

using namespace std;

class Solution {
public:

    map <string, int> map1 = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000},
    };

//    map1["I"] = 1;
//    map1["V"] = 5;
//    map1["X"] = 10;
//    map1["L"] = 50;
//    map1["C"] = 100;
//    map1["D"] = 500;
//    map1["M"] = 1000;

    int romanToInt(string s) {
        map<string, int>::iterator it = map1.begin();

        cout << s <<"\n";

//        while (it != map1.end())
//        {
//            cout << "Key: " << it->first << ", Value: " << it->second << endl;
//            ++it;
//        }

        int sum = 0;
        int maxx = 0;
        string first;
        first = s[s.size()];
        maxx = map1[first];

        for( int i = s.size() - 1; i > -1; i--){
            //cout << "I is " << i << " \n";
            string s1, s2;
            s1 = s[i];
            //i == 0 ? s2 = "N" : s2 = s[i - 1];
            //s2 = s[i - 1];

            //cout <<"S1 = "<<s1 <<"  S2 = " << s2 << " \n";
            //cout << map1[s1] <<" " << map1[s2] << " ";

//            if(map1[s1] <= map1[s2]){
//                sum = sum + map1[s1] + map1[s2];
//                cout << "Adding";
//            }
//            else if(map1[s1] > map1[s2] && map1[s2] != 0){
//                sum = sum + map1[s1] - map1[s2];
//                cout << "SubTracting";
//            }
//            else{
//                sum = sum + map1[s1];
//                cout << "Adding";
//            }

            if(map1[s1] >= maxx){
                sum = sum + map1[s1];
            }
            else{
                sum = sum - map1[s1];
            }

            if( maxx < map1[s1] ) maxx = map1[s1];


            cout<<"\nSum is = " <<sum <<"\n";

        }
        //cout<<"\nSum is = " <<sum <<"\n";

        return sum;

    }
};

int main()
{
    Solution s1;

    cout << s1.romanToInt("MCMXCIV");

    return 0;
}
