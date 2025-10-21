class Solution {
private:
    bool isValid(vector<int>&nums,int mid,int k,int n){
    int cnt=1;
    int sum=0;
    for(auto &val:nums){
        if(sum+val<=mid){
            sum+=val;
        }
        else{
            cnt++;
            sum=val;
        }
        if(cnt>k)return false;
    }

    return true;
}
public:
int splitArray(vector<int>&nums,int k){
    long long total=accumulate(nums.begin(),nums.end(),0LL);
    int low=*max_element(nums.begin(),nums.end());
    int high=total;
    int ans=-1;
    while (high>=low){
        int mid=(low+high)/2;
        if(isValid(nums,mid,k,nums.size())){
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;
        }

    }
    return ans;
}
};