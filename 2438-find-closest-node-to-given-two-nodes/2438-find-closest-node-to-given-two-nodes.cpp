class Solution {
public:
    vector<int> getDistances(int start,  vector<int>& edges) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int d = 0, curr = start;
        while (curr != -1 && dist[curr] == -1) {
            dist[curr] = d++;
            curr = edges[curr];
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1 = getDistances(node1, edges);
        vector<int> d2 = getDistances(node2, edges);

        int minDist = INT_MAX, ans = -1;
        for (int i = 0; i < n; i++) {
            if (d1[i] != -1 && d2[i] != -1) {
                int maxDist = max(d1[i], d2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
