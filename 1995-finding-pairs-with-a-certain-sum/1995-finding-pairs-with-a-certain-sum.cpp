class FindSumPairs {
    vector<int>nums1,nums2;
    map<int,int>mp;
public:
    FindSumPairs(vector<int>& arr, vector<int>& brr) {
        nums1 = arr;
        nums2 = brr;
        for(auto & val : nums2)mp[val]++;
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index] += val;
        mp[nums2[index]]++;
        
    }
    
    int count(int tot) {
        int cnt = 0;
        // for(int i = 0;i < nums1.size(); i++){
        //     for(int j = 0; j < nums2.size(); j++){
        //         long long sum = nums1[i] + nums2[j];
        //         if(sum ==tot)cnt++;

        //     }
        // }
        for (int x : nums1) {
            int need = tot - x;
            cnt += mp[need];
        }
        return cnt;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */