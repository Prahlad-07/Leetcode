class FindSumPairs {
    vector<int>nums1, nums2;
    map<int, int> freq2;  // Maintain frequency map for nums2

public:
    FindSumPairs(vector<int>& arr, vector<int>& brr) {
        nums1 = arr;
        nums2 = brr;
        for (int x : nums2) freq2[x]++;
    }
    
    void add(int index, int val) {
        freq2[nums2[index]]--;  // Remove old value count
        nums2[index] += val;
        freq2[nums2[index]]++;  // Add new value count
    }
    
    int count(int tot) {
        int cnt = 0;
        for (int a : nums1) {
            int need = tot - a;
            cnt += freq2[need];
        }
        return cnt;
    }
};
