class Solution {
    using ll=long long;
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size(),k=n/3;
        vector<ll> pre(n,0),suf(n,0);
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>,greater<int>> min_heap;
        ll sum=0;
        for(int j=0;j<n;++j){
            int i=nums[j];
            if(max_heap.size()<k){
                max_heap.push(i);
                sum+=i;
            } else if(max_heap.top()>i){
                sum-=max_heap.top();max_heap.pop();
                sum+=i;
                max_heap.push(i);
            }
            pre[j]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            int num=nums[i];
            if(min_heap.size()<k){
                min_heap.push(num);
                sum+=num;
            } else if(min_heap.top()<num){
                sum-=min_heap.top();min_heap.pop();
                sum+=num;
                min_heap.push(num);
            }
            suf[i]=sum;
        }
        ll res=LLONG_MAX;
        for(int i=k-1;i<2*k;i++){
            res = min(res,pre[i]-suf[i+1]);
        }
        return res;
    }
};