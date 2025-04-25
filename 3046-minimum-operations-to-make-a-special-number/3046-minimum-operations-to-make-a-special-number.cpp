class Solution {
public:
    int minimumOperations(string s) {
        int n=s.size();
        int mini=n;
        if(n==1 && s[0]=='0'){
            return 0;
        }
        if(n==1)return 1;

        int j=n-1;
        while(j>=0){
            if(s[j]=='0'){
                int i=j-1;
                while(i>=0 && s[i]!='0' && s[i]!='5'){
                    i--;
                }
                if(i>=0)mini=min(mini,n-i-2);
            }
            if(s[j]=='5'){
                int i=j-1;
                while(i>=0 && s[i]!='2' && s[i]!='7'){
                    i--;
                }
                if(i>=0)mini=min(mini,n-i-2);
            }
            j--;
        }

        // special case to make number "0"
        int f=0,i=0;
        while(i<n){
            if(s[i]=='0'){
                f=1;
                break;
            }
            i++;
        }
        if(f)mini=min(mini,n-1);

        return mini;
    }
};
