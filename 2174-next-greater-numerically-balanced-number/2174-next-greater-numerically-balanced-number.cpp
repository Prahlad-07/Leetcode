class Solution {
private:
    bool isBeautifull(int n){
        vector<int>freq(10 ,0);
        while(n > 0){
            int rem = n % 10;
            n/= 10;
            freq[rem]++;
        }

        for(int i = 0; i < 10; i++){
            if(freq[i] > 0 && freq[i] != i)return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        n++;
        while(true){
            if(isBeautifull(n)){
                return n;
            }
            n++;
        }
        return 0;
    }
};