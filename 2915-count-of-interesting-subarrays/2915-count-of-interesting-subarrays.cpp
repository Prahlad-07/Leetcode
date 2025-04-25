class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // long long cnt=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int c=0,j=i;
        //     while(j<n){
        //         if(nums[j]%modulo==k)c++;
        //         if(c%modulo==k)cnt++;
        //         j++;
        //     }
        // }
        // return cnt;
        
        
        long long cnt=0;
        int n=nums.size();
        unordered_map<int,long long> mp;
        mp[0]=1;
        int s=0;
        int i=0;
        while(i<n){
            if(nums[i]%modulo==k)s++;
            int mod=s%modulo;
            int need=(mod-k+modulo)%modulo;
            if(mp.count(need))cnt+=mp[need];
            mp[mod]++;
            i++;
        }
        return cnt;
    }
};
