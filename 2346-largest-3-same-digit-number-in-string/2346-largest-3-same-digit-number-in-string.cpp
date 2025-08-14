class Solution {
public:
    string largestGoodInteger(string num) {
        string maxi = "";
        int temp = -1;
        for(int i = 0;i < num.size(); i++){
            string s = num.substr(i, 3);
            int val = stoi(s);
            cout<<val<<" ";
            if(s.size()==3 && (s[0] == s[1] && s[1] == s[2]) ){
                 if(val >= temp){
                maxi = s;
                temp = val;
                }
            }

        }
        return maxi;
    }
};