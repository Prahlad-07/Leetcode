class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            int sum=0;
            for(auto &ch:s){
                sum+=(ch-'0');
            }
            mp[sum]++;
        }
        int mx=0, cnt=0;
        for(auto &[k,v]:mp){
            if(v > mx){
                mx = v;
                cnt = 1;
            }
            else if(v == mx){
                cnt++;
            }
        }
        return cnt;
    }
};
