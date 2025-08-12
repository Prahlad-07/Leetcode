class Solution {
const int wife=1e9+7;
int sonal[301][301];
private:
int F_P_F(int base, int exp) {
    int result=1;
    while (exp>0) {
        if (exp % 2==1)result=(1LL*result*base) %wife;
        base =(1LL*base*base)%wife;
        exp/=2;
    }
    return result;
}
int solve(int val,int n, int x,int sum){
    if(sum>n)return 0;
    if(sum==n)return 1;
    if(val>n)return 0;
    if(sonal[val][sum]!=-1)return sonal[val][sum];
    int value=F_P_F(val,x);
    int take=0, not_take=0;
    if(sum + value <= n) {
        take=solve(val+1,n,x,sum+value);
    }
    not_take=solve(val+1,n,x,sum);
    sonal[val][sum]=(take+not_take)%wife;
    return sonal[val][sum];
}



public:
    int numberOfWays(int n, int x) {
        // if(x>n)return 0;
        memset(sonal,-1,sizeof(sonal)); 
        return solve(1,n,x,0);
    }
};