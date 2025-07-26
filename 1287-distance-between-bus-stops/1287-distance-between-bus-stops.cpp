class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int idx = start;
        int dist = 0;
        if (start == destination) return 0;
        while (true) {
             if (idx == destination) break;
            dist += distance[idx];
            if (idx == n - 1) idx = 0;
            else idx++;
        }
        if(start == 0) idx = n-1;
        else idx = start - 1;
        int mini = INT_MAX;
        mini = min(dist, mini);
        dist = 0;
        while (true) {
            dist += distance[idx];
            if (idx == destination) break;
            if (idx == 0) idx = n - 1;
            else idx--;
        }
        mini = min(dist, mini);
        return mini;
    }
};
