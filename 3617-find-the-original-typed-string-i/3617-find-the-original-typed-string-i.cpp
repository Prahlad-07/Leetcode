class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=1;
        int idx=0;
        while(idx<word.size()){
            char ch=word[idx];
            int same=0;
            while(idx<word.size() && word[idx] == ch){
                idx++;
                same++;
                
            }
            // cout<<j-idx<<endl;
            cnt+=(same-1);
            
        }
        return cnt;
        
    }
};