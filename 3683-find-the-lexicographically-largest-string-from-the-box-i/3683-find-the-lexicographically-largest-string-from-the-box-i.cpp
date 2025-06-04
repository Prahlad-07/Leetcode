class Solution {
public:
    string answerString(string word, int numFriends) {
        // int n = word.size();
        // if (numFriends == 1) return word;

        // int maxLen = n - numFriends + 1; 
        // string ans = "";

        // for (int i = 0; i < n; i++) {
        //     string temp = "";
        //     for (int j = i; j < n; j++) {
        //         temp += word[j];
        //         if (j - i + 1 <= maxLen) {
        //             ans = max(ans, temp);
        //         } else break;
        //     }
        // }

        // return ans;
        if(numFriends==1)return word;

        string ans="";
        for(int i=0;i<word.size();i++){
            int len = min(word.size()-i,word.size()-numFriends+1);
            if(len<=0)continue;
            string str=word.substr(i,len);
            ans=max(ans,str);
        }
        return ans;

        
    }
};
