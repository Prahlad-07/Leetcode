class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int left = 0, right = height.size() - 1;
        while(left < right){
            int mini = min(height[left], height[right]);
            maxi = max(maxi, (right - left) * mini);
            if(height[left] > height[right]){
                right--;
            }
            else left++;
        } 

        return maxi;        
    }
};