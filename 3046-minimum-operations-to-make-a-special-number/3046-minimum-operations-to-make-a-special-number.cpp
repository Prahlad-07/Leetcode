class Solution {
public:
    int minimumOperations(string s) {
        int n = s.size();
        int mini = n;

        if(n == 1 && s[0] == '0') return 0;
        if(n == 1) return 1;

        for(int j = n - 1; j >= 0; j--) {
            if(s[j] == '0') {
                for(int i = j - 1; i >= 0; i--) {
                    if(s[i] == '0' || s[i] == '5') {
                        mini = min(mini, n - i - 2);
                        break;
                    }
                }
            }
            if(s[j] == '5') {
                for(int i = j - 1; i >= 0; i--) {
                    if(s[i] == '2' || s[i] == '7') {
                        mini = min(mini, n - i - 2);
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                mini = min(mini, n - 1);
                break;
            }
        }

        return mini;
    }
};
