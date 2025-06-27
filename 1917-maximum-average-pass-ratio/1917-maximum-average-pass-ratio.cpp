class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for(auto &v : classes){
            int pass = v[0], total = v[1];
            double delta = ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
            pq.push({delta, {pass, total}});
        }

        while(extraStudents > 0){
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            
            pass += 1;
            total += 1;
            
            double delta = ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
            pq.push({delta, {pass, total}});
            extraStudents--;
        }

        double avg = 0.0;
        while(!pq.empty()){
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            avg += (double)pass / total;
            pq.pop();
        }
        
        return avg / classes.size();
    }
};
