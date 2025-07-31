class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        int n=arr.size();
        for(int i=0; i<n; i++){
            int val=arr[i];
            int notTake=0, take=val;
            ans.insert(take);
            for(int j=i-1; j>=0; j--){
                notTake|=arr[j];
                take=notTake|val;
                if (notTake==take) break;
                ans.insert(take);
            }
        }   
        return ans.size();
    }
};