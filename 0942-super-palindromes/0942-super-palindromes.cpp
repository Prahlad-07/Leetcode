class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    int superpalindromesInRange(string left, string right) {
        // long long l = stoll(left), r = stoll(right);
        // int cnt = 0;
        // long long start = 1;

        // while (start * start < l) start++;

        // while (start * start <= r) {
        //     long long val = start * start;
        //     string s = to_string(start);
        //     if (isPalindrome(s) && isPalindrome(to_string(val))) {
        //         cnt++;
        //     }
        //     start++;
        // }

        // return cnt;


        long long l = stoll(left), r = stoll(right);
        int count = 0;

        for (int len = 1; len <= 9; len++) {
            int start = pow(10, (len - 1) / 2);
            int end = pow(10, (len + 1) / 2);

            for (int half = start; half < end; half++) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());

                string full;
                if (len % 2 == 0) {
                    full = s + rev;
                } else {
                    full = s + rev.substr(1);
                }

                long long num = stoll(full);
                long long sq = num * num;
                if (sq > r) break;
                if (sq >= l && isPalindrome(to_string(sq))) {
                    count++;
                }
            }
        }

        return count;
    }
};
