class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
    //     set<int>st;
    //     for(int i=0;i<digits.size();i++){
    //         for(int j=0;j<digits.size();j++){
    //             if(i==j)continue;
    //             for(int k=0;k<digits.size();k++){
    //                 if(j==k || k==i || digits[i]==0)continue;
    //                 string s="";
    //                 s+=to_string(digits[i]);
    //                 s+=to_string(digits[j]);
    //                 s+=to_string(digits[k]);
    //                 int val=stoi(s);
    //                 if(!(val&1))st.insert(val);
                    
    //             }
    //         }
    //     }
        
    //  vector<int>ans(st.begin(),st.end());
    //     return ans;
    map<int,int>mp;
    for(auto &i:digits){
        mp[i]++;
    }

    vector<int>ans;
    for(int i=100;i<=998;i+=2){
        string s=to_string(i);
        // // bool flag = true;
        // // for(int i=0;)
        // int dig1=s[0]-'0';
        // int dig2=s[1]-'0';
        // int dig3=s[2]-'0';
        // int one=0,zero=0,three=0;
        // if(dig1==dig2){
        //     one++;
        //     two--        // <- this line is commented out as it contains an error
        // }
        // if(two==3){
        //     two++        // <- this line is commented out as it contains an error
        // }
        map<int,int>temp;
        for(auto &x:s){
            temp[x-'0']++;
        }
        bool flag=true;
        for(auto &[val,f]:temp){
            if(mp[val]<f)flag=false;
        }
        if(flag)ans.push_back(i);
    }

    return ans;
    }
};
