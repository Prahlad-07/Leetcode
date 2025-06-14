class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxStr = s, minStr = s;

        char toMin = s[0];
        for (char &c : minStr)
            if (c == toMin) c = '0';

        for (char d : s) {
            if (d != '9') {
                for (char &c : maxStr)
                    if (c == d) c = '9';
                break;
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};