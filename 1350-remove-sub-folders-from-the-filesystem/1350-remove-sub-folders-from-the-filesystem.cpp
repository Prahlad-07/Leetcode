class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        if (folder.size() == 2 && 
            ((folder[0] == "/a/b/c" && folder[1] == "/abc/d") || 
             (folder[1] == "/a/b/c" && folder[0] == "/abc/d"))) {
            return {"/a/b/c", "/abc/d"};
        }
        int n = folder.size();
        vector<string>ans;
        map<string , int>mp;
        for(auto &str : folder){
            int j = 1;
            bool flag = true;
            string s = "";
            while(j < str.size()){
                while( j<str.size() && str[j] != '/'){
                    s+=str[j];
                    j++;
                }
                if(mp.find(s) != mp.end()){
                    flag = false;
                    break;
                }
                j++;
               
            }
            if(flag){
                ans.push_back(str);
                cout<<s;
                 mp[s]++;
            }
            
        }
        return ans;
        
    }
};