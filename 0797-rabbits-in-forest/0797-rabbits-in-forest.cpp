class Solution {
public:
    int numRabbits(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size(),i=0,ans=0;
        while(i<n){
            int x=a[i],c=0;
            while(i<n&&a[i]==x&&c<x+1)i++,c++;
            ans+=x+1;
        }
        return ans;
    }
};
