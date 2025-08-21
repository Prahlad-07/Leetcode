class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        bool flag = false;
        for(int i = 1; i < n; i++){
            if(end < intervals[i][0]){
                ans.push_back({start, end});
                start = intervals[i][0], end = intervals[i][1];
                // flag = true;
            }
            // else {
            //     end = intervals[i][1];
            //     flag = false;
            // }
            else {
                end = max(end, intervals[i][1]);
            }
            

        }
        // if(flag==false)
        ans.push_back({start, end});
        cout<<start <<" "<<end<<endl;
        return ans;

        

        
    }
};