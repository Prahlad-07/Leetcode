class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        // int cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         if(j-i+1==3 && ((nums[i]+nums[i+2])==float(nums[i+1]/2.0)))cnt++;
        //     }
        // }
        // return cnt;
        int n = nums.size();
        int cnt = 0;
        int j = 0 , i = 0;
        while( j < n ){
            if(j-i+1==3) {
                if(nums[i]+nums[j]==float(nums[i+1]/2.0)) cnt++;
                i++;
            }
            j++;
        }
        return cnt;
        
    }
};