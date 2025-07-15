class Solution {
public:
    bool isValid(string s) {
        int a=(s.size()>=3),b=1,c=0,d=0;
        vector<int> e={'a','e','i','o','u','A','E','I','O','U'}; 
        for (auto r:s) {
            int p=0;
            for (int j = 0; j < 26; j++) 
            if (r-'a'==j||r-'A'==j) p=1; 
            for (int j = 0; j < 10; j++) 
            if (r-'0'==j) p=2;
            if (!p) b=0; 
            if (p>1) continue;
            p=1;
            for (auto j:e) if (r==j) p=0;
            if (p) c=1;
            else d=1; 
        }
        return a&&b&&c&&d;
    }
};