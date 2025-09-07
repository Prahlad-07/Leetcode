class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n & 1) ans.push_back(0);
        int values = n/2;
        while(values > 0){
            ans.push_back(values);
            ans.push_back(-values);
            values--;
        }
        return ans;


    }
};