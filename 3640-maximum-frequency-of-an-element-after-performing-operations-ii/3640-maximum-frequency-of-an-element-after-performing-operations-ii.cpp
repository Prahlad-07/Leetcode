class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        map<int,int>mp, freq;
        int n = nums.size();
        for(auto &val : nums){
            freq[val]++;
            int temp = max(0, val - k);
            mp[temp]++;
            mp[val] += 0;
            mp[val + k + 1]--;
        }
        int maxi = 1;
        int line = 0;
        for(auto &[v, f] : mp){
            line += f;
            int p = line - freq[v];
            int x= min(numOperations, p);
            maxi = max(maxi, x + freq[v]);
        }
        return maxi;

        // sort(nums.begin(), nums.end());
        // int  left = 0, right = 0;
        // long long sum = 0;
        // int maxi = 0;
        // while(right < nums.size()){
        //     sum += nums[right];
        //     while(1LL * (right - left + 1) * nums[right] - sum > numOperations){
        //         left++;
        //     }
        //     maxi = max(maxi, right - left + 1);
        //     right++;
        // }
        // return maxi;
        
        
        // 
        // int maxi = 0;
        // sort(nums.begin(), nums.end());
        // map<int, int> mp;
        // for (auto &val : nums) mp[val]++;

        // for (int i = 0; i < nums.size(); i++) { 
        //     int left = nums[i] - k, right = nums[i] + (2 *k);
        //     int leftIdx = lower_bound(nums.begin(), nums.end(), left) - nums.begin();
        //     int rightIdx = upper_bound(nums.begin(), nums.end(), right) - nums.begin();
        //     int dist = rightIdx - leftIdx;
        //     int op = dist - mp[nums[i]] ;
        //     if(op > numOperations){
        //         maxi = max(maxi, mp[nums[i]] + numOperations);
        //     }
        //     else maxi = max(maxi, dist);
        //     cout << dist << endl;
        // }
        // // if(maxi <= 1 && numOperations >= 2){
        // //     for(int i = 1; i < nums.size(); i++){
        // //         int val1 = nums[i] -  (2 * k);
        // //         int val2 = nums[i-1] + k;
        // //         if(val1 <= val2) maxi = 2;
        // //     }
        // // }
        // return maxi;
        // int maxi = 0;
        // sort(nums.begin(), nums.end());
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {
        //     int left = 0, right = i;
        //     int bestLeft = i;

        //     while (left <= right) {
        //         int mid = (left + right) / 2;
        //         long long ops = 0;
        //         for (int j = mid; j <= i; j++) {
        //             ops += nums[i] - nums[j];
        //         }

        //         if (ops <= numOperations) {
        //             bestLeft = mid;
        //             right = mid - 1;
        //         } else {
        //             left = mid + 1;
        //         }
        //     }

        //     maxi = max(maxi, i - bestLeft + 1);
        // }

        // return maxi;
    }
};
