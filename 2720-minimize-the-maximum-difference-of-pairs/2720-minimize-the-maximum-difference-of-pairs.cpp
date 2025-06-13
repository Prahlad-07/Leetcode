class Solution {
private:
bool isValid(vector<int>&nums,int mid,int p){
    int n=nums.size();
    int i=1;
    int cnt=0;
    while(i<n){
        int diff=nums[i]-nums[i-1];
        if(diff<=mid){
            cnt++;
            i+=2;
        }
        else{
            i+=1;
        }
        if(cnt>=p)return true;
        
    }
    return false;
    
}
public:
    int minimizeMax(vector<int>& nums, int p) {
        //Radhe Radhe-->
        int n=nums.size();
        
 
        int maxi=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
        int left=0;
        int right=maxi;
        sort(nums.begin(),nums.end());
        while(left<right){
            int mid=(left+right)/2;
            if(isValid(nums,mid,p)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
