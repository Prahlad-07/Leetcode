class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

    /*

    //brute force--->


        sort(nums.begin(),nums.end());
        int x = INT_MIN;
        set<int> st;
        // st.insert(nums[0]-k);
        for (auto &i:nums) {
            int val=i-k;
            x=max(val,x);
            int y =INT_MIN;
            for (int value=x;value<=i+k;value++) {
                if (st.find(value)==st.end()) {
                    y=value;
                    break;
                }
            }
            // y==INT_MIN?st.insert(i):st.insert(y);
            // x=y+1;
            if(y==INT_MIN){
                st.insert(i);
                x=i;
            }
            else{
                x=y;
                st.insert(y);
            }
        }
        return st.size();

        */


        /*

        optimal one--->


        sort(nums.begin(),nums.end());
        priority_queue<int> pq;
        set<int> st;
        pq.push(nums[0]-k);
        st.insert(nums[0]-k);
        for(int i=1;i<nums.size();i++){
            int val=pq.top();
            int x=nums[i]-k;
            int y =INT_MIN;
            for(int value=max(val+1,x);value<=nums[i]+k;value++){
                if (st.find(value)==st.end()) {
                    y=value;
                    break;
                }
            }
            if(y==INT_MIN){
                st.insert(nums[i]);
                pq.push(nums[i]);
            }
            else{
                st.insert(y);
                pq.push(y);
            }
        }
        return st.size();
        */


        // more optimal---->constant space and nlogn time--->


       int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        int prev=nums[0]-k;
        for(int i=1;i<n;i++){
            int val=nums[i]-k;
            if(val>prev){
                cnt++;
                prev=val;
            }
            else {
                if(prev+1<=nums[i]+k){
                    cnt++;
                    prev+=1;
                }
            }
        }
        return cnt;
        

        

    }
};