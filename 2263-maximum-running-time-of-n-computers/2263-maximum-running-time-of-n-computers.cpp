class Solution {
    bool isValid(vector<int>&batteries, int n, int mid){
        int cnt = 0;
        long long rem = 0;
        for(auto &val : batteries){
            if(val + rem >= mid){
                rem = (val + rem) - mid;
                cnt++;
            }
            else{
                rem += val;
            }
            if(cnt >= n)return true;
        }
        return cnt >= n;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        // int  = batteries.size();
      
        long long sum = 0;
        for(auto &b : batteries) sum += b;
        sort(batteries.begin(), batteries.end());
        long long low = 0, high = sum / n;
        long long ans = 0;
        while(low <= high){
            long long mid = (low + high)/2;
            if(isValid(batteries, n, mid)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    
    }
};