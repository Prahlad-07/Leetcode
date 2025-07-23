class Solution {
public:
    int maximumGain(string s, int x, int y) {
        /*
        basic string manipulation and pattern finding :)
        Day-2
        */
        int cnt = 0;
        string pattern1 = "ab", pattern2 = "ba";
        
        if (y > x) {
            swap(x, y);
            swap(pattern1, pattern2);
        }
        
        cnt += removeAndCount(s, pattern1, x);
        cnt += removeAndCount(s, pattern2, y);
        
        return cnt;
    }
    
    int removeAndCount(string &s, const string &pattern, int value) {
        int cnt = 0;
        size_t pos = 0;
        
        while ((pos = s.find(pattern, pos)) != string::npos) {
            s.erase(pos, 2);
            cnt += value;
            if (pos > 0) pos--; 
        }
        
        return cnt;
    }
};