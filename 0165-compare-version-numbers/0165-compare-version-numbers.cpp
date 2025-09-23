class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while(i < version1.size() || j < version2.size()){
            string s = "";
            int idx = i;
            while(idx < version1.size() && version1[idx] != '.'){
                s += version1[idx];
                idx++;
            }
            int val1 = s.empty() ? 0 : stoi(s);
            s = "";
            i = idx + 1;

            idx = j;
            while(idx < version2.size() && version2[idx] != '.'){
                s += version2[idx];
                idx++;
            }
            int val2 = s.empty() ? 0 : stoi(s);
            j = idx + 1;

            if(val1 < val2) return -1;
            if(val1 > val2) return 1;
        }
        return 0;
    }
};
