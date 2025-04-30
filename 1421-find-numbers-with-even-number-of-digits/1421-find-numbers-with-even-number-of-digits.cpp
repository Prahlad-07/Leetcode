class Solution {
public:
    int findNumbers(vector<int>& nums) {
         // Approach -> 1
         
        // int cnt=0;
        // for(auto &val:nums){
        //     string s=to_string(val);
        //     if(!(s.size()&1))cnt++;
        // }
        // return cnt;
        // Approach -> 2

        int cnt=0;
        for(auto &val:nums){
            int x=0;
            while(val>0){
                val/=10;
                x++;
            }
            if(!(x&1))cnt++;
        }
        return cnt;
        
    }
};