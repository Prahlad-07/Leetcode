class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            string curr = words[i];
            string last = ans.back();
            string sortedCurr = curr;
            string sortedLast = last;
            sort(sortedCurr.begin(), sortedCurr.end());
            sort(sortedLast.begin(), sortedLast.end());

            if (sortedCurr != sortedLast)
                ans.push_back(curr);
        }

        return ans;
    }
};
