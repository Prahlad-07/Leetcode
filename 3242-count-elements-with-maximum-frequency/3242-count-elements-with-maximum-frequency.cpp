class Solution {
public:

static bool cmp(int a,int b)
{
    return a>b;
}
    int maxFrequencyElements(vector<int>& nums) {
    
        

        int n=nums.size();
map<int,int>mp;
    for(auto i:nums)
    {
        mp[i]++;
    }
int cnt=0;
    vector<int>temp;
    for(auto i:mp)
    {
        temp.push_back(i.second);
    }
   int max=*max_element(temp.begin(),temp.end());
   for(auto i:temp)
   {
       if(i==max)
       {
           cnt+=i;
       }
   }
   return cnt;
     
    }
};