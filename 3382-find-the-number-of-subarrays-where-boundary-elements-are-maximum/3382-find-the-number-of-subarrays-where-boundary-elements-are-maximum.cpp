class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        // long long cnt=0;
        // int n=nums.size();
        // for(int i=0;i<nums.size();i++){
        //     int maxi=nums[i];
        //     for(int j=i;j<nums.size();j++){
        //         maxi=max(maxi,nums[j]);
        //         if(nums[i]==maxi && nums[j]==maxi)cnt++;
        //     }
        // }
        // return cnt;
        
        int n=nums.size();
        long long cnt=0;

        vector<int> tree(4*n);
        function<void(int,int,int)> build=[&](int v,int l,int r){
            if(l==r)tree[v]=nums[l];
            else{
                int m=(l+r)/2;
                build(v*2,l,m);
                build(v*2+1,m+1,r);
                tree[v]=max(tree[v*2],tree[v*2+1]);
            }
        };

        function<int(int,int,int,int,int)> query=[&](int v,int tl,int tr,int l,int r){
            if(l>r)return INT_MIN;
            if(tl==l && tr==r)return tree[v];
            int tm=(tl+tr)/2;
            return max(
                query(v*2,tl,tm,l,min(r,tm)),
                query(v*2+1,tm+1,tr,max(l,tm+1),r)
            );
        };

        build(1,0,n-1);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)mp[nums[i]].push_back(i);

        for(auto &[val,v]:mp){
            int sz=v.size();
            int l=0;
            for(int r=0;r<sz;r++){
                while(l<=r && query(1,0,n-1,v[l],v[r])>val)l++;
                cnt+=(r-l+1);
            }
        }

        return cnt;
    }
};
