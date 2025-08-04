class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxi = 1;
        int i = 0;
        map<int,int>mp;
        int j = 0;
        for(auto &fal : fruits){
            mp[fal]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
        
    }
};