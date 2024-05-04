class Solution {
public:
    int compareVersion(string version1, string version2) {
        int rv1 = 0, rv2 = 0;
        int dot = 0, prv_dot = 0;
        for(int i = 0; i < version1.size();i++){
            cout << version1[i] << "\n";
            if(version1[i] == '.'){prv_dot = dot; dot++;}
            if(dot == 0 && version1[i] != '0' && version1[i] != '.'){
                rv1 = rv1 + 500;
                prv_dot = dot;
                dot ++;
            }
            else if(dot > prv_dot && version1[i] != '0' && version1[i] != '.'){
                rv1 = rv1 + (500 - dot);
                prv_dot = dot;
                dot ++;
            }
        }
        cout << rv1 << "\n";
        dot = 0; prv_dot = 0;
        for(int i = 0; i < version2.size();i++){
            cout << version2[i] << "\n";
            if(version2[i] == '.'){prv_dot = dot; dot++;}
            if(dot == 0 && version2[i] != '0' && version2[i] != '.'){
                rv2 = rv2 + 500;
                prv_dot = dot;
                dot ++;
            }
            else if(dot > prv_dot && version2[i] != '0' && version2[i] != '.'){
                rv2 = rv2 + (500 - dot);
                prv_dot = dot;
                dot ++;
            }
        }
        cout << rv2 << "\n";

        if(rv1 > rv2){return 1;}
        else if(rv2 > rv1){return -1;}
        else{return 0;}
    }
};







class Solution {
public:
    int compareVersion(string version1, string version2) {
        int rv1 = 0, rv2 = 0;
        int dot1 = 0, prv_dot = 0;
        for(int i = 0; i < version1.size(); i++){
            if(version1[i] == '.'){dot1++;}
            if(version1[i] != '0' && version1[i] != '.'){
                rv1 = rv1 + (version1[i] - '0')+(10 - ((dot1+1)*(dot1+1)));
                cout << ((version1[i] - '0')+(10 - ((dot1+1)*(dot1+1)) )) << " \n";
                cout << (10 - ((dot1+1)*(dot1+1))) << " \n\n";
            }
        }
        cout << "\n\n";
        int dot2 = 0;
        for(int i = 0; i < version2.size(); i++){
            if(version2[i] == '.'){dot2++;}
            if(version2[i] != '0' && version2[i] != '.'){
                rv2 = rv2 + (version2[i] - '0')+(10 - ((dot2+1)*(dot2+1)));
                cout << (version2[i] - '0')+(10 - ((dot2+1)*(dot2+1)) ) << " \n";
            }
        }
        cout << rv1 << " \n";
        cout << rv2 << " \n";
        
        if(rv1 > rv2){return 1;}
        else if(rv2 > rv1){return -1;}
        else{return 0;}
    }
};


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int rv1 = 0, rv2 = 0;
        int dot1 = 0, prv_dot = 0;
        for(int i = 0; i < version1.size(); i++){
            if(version1[i] == '.'){prv_dot = 1; dot1++;}
            if(version1[i] == 0 && dot1 == 0){continue;} 
            if(version1[i] == 0 && prv_dot == 1){continue;}
            if(version1[i] != '.'){
                prv_dot = 0;
                rv1 = rv1 + (version1[i] - '0')+(10 - ((dot1+1)*(dot1+1)));
                cout << ((version1[i] - '0')+(10 - ((dot1+1)*(dot1+1)) )) << " \n";
                cout << (10 - ((dot1+1)*(dot1+1))) << " \n\n";
            }
        }
        cout << "\n\n";
        int dot2 = 0;
        prv_dot = 0;
        for(int i = 0; i < version2.size(); i++){
            if(version2[i] == '.'){prv_dot = 1; dot2++;}
            if(version2[i] == 0 && dot2 == 0){continue;} 
            if(version2[i] == 0 && prv_dot == 1){continue;}
            if(version2[i] != '.'){
                rv2 = rv2 + (version2[i] - '0')+(10 - ((dot2+1)*(dot2+1)));
                cout << (version2[i] - '0')+(10 - ((dot2+1)*(dot2+1)) ) << " \n";
            }
        }
        cout << rv1 << " \n";
        cout << rv2 << " \n";
        
        if(rv1 > rv2){return 1;}
        else if(rv2 > rv1){return -1;}
        else{return 0;}
    }
};









class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i, j;

        // Create vectors to store the integer parts of version strings version1 and version2
        vector<int> version1Parts;
        vector<int> version2Parts;

        // Extract integer parts from version string version1
        for (i = 0; i < version1.size(); i++) {
            string part;
            j = i;
            while (j < version1.size() && version1[j] != '.') part += version1[j++];

            i = j;
            version1Parts.push_back(stoi(part)); // Convert the extracted string to an integer and store in vector version1Parts
        }

        // Extract integer parts from version string version2
        for (i = 0; i < version2.size(); i++) {
            string part;
            j = i;
            while (j < version2.size() && version2[j] != '.') part += version2[j++];

            i = j;
            version2Parts.push_back(stoi(part)); // Convert the extracted string to an integer and store in vector version2Parts
        }

        // Compare the corresponding integer parts of versions version1 and version2
        i = 0;
        j = 0;
        while (i < version1Parts.size() && j < version2Parts.size()) {
            if (version1Parts[i] > version2Parts[j]) return 1; // If version version1 is greater than version version2, return 1
            else if (version1Parts[i] < version2Parts[j]) return -1; // If version version1 is less than version version2, return -1
            i++;
            j++;
        }

        // Handle cases where one version string has more integer parts than the other and the remaining parts are all 0
        while (i < version1Parts.size() && version1Parts[i] == 0) i++;
        while (j < version2Parts.size() && version2Parts[j] == 0) j++;

        // Check if there are remaining non-zero integer parts in version version1
        if (i < version1Parts.size()) return 1; // If version version1 has more non-zero parts, it is greater, so return 1
        // Check if there are remaining non-zero integer parts in version version2
        if (j < version2Parts.size()) return -1; // If version version2 has more non-zero parts, it is greater, so return -1
        // Both versions are equal
        return 0;

        // This line is unreachable, as the function returns before reaching it
        return 1;
    }
};