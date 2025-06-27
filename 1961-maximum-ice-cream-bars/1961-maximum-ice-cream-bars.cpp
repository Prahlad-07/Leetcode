class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt=0;
        sort(costs.begin(),costs.end());
        for(auto &val : costs){
            if(val<=coins){
                coins-=val;
                cnt++;
            }
        }
        return cnt;
        
    }
};