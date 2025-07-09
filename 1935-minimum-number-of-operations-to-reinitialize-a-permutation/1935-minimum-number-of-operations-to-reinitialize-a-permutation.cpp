class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            arr[i]=i;
        }
        int cnt=0;
        vector<int>perm=arr;
        while(true){
            vector<int>temp(n,0);
            for(int i=0;i<n;i++){
                if(i&1){
                    temp[i]=perm[n/2+(i-1)/2];
                }
                else{
                    temp[i]=perm[i/2];
                }
            }
            perm=temp; 
            cnt++;
            if(perm==arr)break;
        }
        return cnt;
    }
};