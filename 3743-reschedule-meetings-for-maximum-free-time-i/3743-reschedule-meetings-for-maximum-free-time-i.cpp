class Solution {
private:
    int calculate_max(vector<int>& gap, int k) {
        int maxi = 0;
        for (int i = 0; i < k + 1; i++) {
            maxi += gap[i];
        }
        int sum = maxi;
        int i = k + 1;
        while (i < gap.size()) {
            sum += gap[i] - gap[i - k - 1];
            maxi = max(maxi, sum);
            i++;
        }
        return maxi;
    }
public:
    int maxFreeTime(int event, int k, vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> p;
        int n = start.size();
        for (int i = 0; i < n; i++) {
            p.push_back({start[i], end[i]});
        }
        sort(p.begin(), p.end());
        vector<int> gap;
        gap.push_back(p[0].first);
        for (int i = 1; i < n; i++) {
            gap.push_back(p[i].first - p[i - 1].second);
        }
        gap.push_back(event - p[n - 1].second);
        int ans = calculate_max(gap, k);
        return ans;
    }
};