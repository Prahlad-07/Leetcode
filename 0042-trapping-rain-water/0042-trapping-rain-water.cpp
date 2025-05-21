class Solution {
public:
    int trap(vector<int>& height) {
int n=height.size();
int left[n];
int right[n];
int maxi=height[0];

for(int i=0;i<n;i++){
       maxi=max(maxi,height[i]);
        left[i]=maxi;
      
}
maxi=height[n-1];
for(int i=n-1;i>=0;i--){
        maxi=max(maxi,height[i]);
       right[i]=maxi;
}
int c=0;
 for(int i=0;i<n;i++){
      c+=min(left[i],right[i])-height[i];
}
return c;

 }

};