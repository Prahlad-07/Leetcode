class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int>mp1;
        map<int,int>mp2;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=bottoms[i]){
                mp1[tops[i]]++;
                mp2[bottoms[i]]++;
                mp2[tops[i]]++;
                mp1[bottoms[i]]++;
                
            }
            else{
                mp1[tops[i]]++;
                mp2[bottoms[i]]++;
            }
        }
        vector<int>vals;
        for(auto &i:mp1){
            if(i.second==tops.size()){
                vals.push_back(i.first);
            }
        }
        int mini=INT_MAX;
        for(auto &val :vals){
            int cnt=0;
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=val)cnt++; 
            }
            mini=min(cnt,mini);
        }
        vals.clear();
        tops=bottoms;
        mp1=mp2;
        for(auto &i:mp1){
            if(i.second==tops.size()){
                vals.push_back(i.first);
            }
        }
        //  mini=INT_MAX;
        for(auto &val :vals){
            int cnt=0;
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=val)cnt++; 
            }
            mini=min(cnt,mini);
        }

        return mini==INT_MAX ? -1:mini;
        
    }
};