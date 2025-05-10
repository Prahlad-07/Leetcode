class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=accumulate(nums1.begin(),nums1.end(),0LL);
        long long sum2=accumulate(nums2.begin(),nums2.end(),0LL);
        int zeroCnt1=count(nums1.begin(),nums1.end(),0);
        int zeroCnt2=count(nums2.begin(),nums2.end(),0);
        long long val1=sum1+zeroCnt1,val2=sum2+zeroCnt2;
        if((val1>val2 && zeroCnt2==0) || (val1<val2 && zeroCnt1==0) ) return -1;
        return max(val1,val2);
        
    }
};