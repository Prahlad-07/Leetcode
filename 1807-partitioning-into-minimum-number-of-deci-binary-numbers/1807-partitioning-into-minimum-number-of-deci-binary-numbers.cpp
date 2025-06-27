class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(auto & val :n){
            maxi=max(maxi,val-'0');
        } 
        return maxi;       
    }
};