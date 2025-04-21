class Solution {
const int mod=1e9+7;
public:
    int numberOfWays(string s) {
        vector<int>pos;
        for(int i=0;i<s.size();i++){
            if(s[i]=='S')
            pos.push_back(i);
        }
        if(pos.size()&1)return 0;
        // int cnt=0;
        if(pos.size()<=2)return pos.size()/2;
        long long cnt=1;
        for(int i=2;i<pos.size();i+=2){
            cnt=(1LL*cnt*((pos[i]-pos[i-1])))%mod;
        }
        return cnt;
    }
};
