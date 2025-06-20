class SegmentTree{
public:
    vector<array<int,4>> t;
    int n;
    SegmentTree(int sz){
        n=sz;
        t.resize(4*n,{0,0,0,0});
    }
    void build(const string&s,int v,int l,int r){
        if(l==r){
            t[v]={0,0,0,0};
            if(s[l]=='E')t[v][0]=1;
            else if(s[l]=='W')t[v][1]=1;
            else if(s[l]=='N')t[v][2]=1;
            else if(s[l]=='S')t[v][3]=1;
        }else{
            int m=(l+r)/2;
            build(s,2*v+1,l,m);
            build(s,2*v+2,m+1,r);
            t[v]=combine(t[2*v+1],t[2*v+2]);
        }
    }
    array<int,4>combine(const array<int,4>&l,const array<int,4>&r){
        array<int,4>res={0,0,0,0};
        for(int i=0;i<4;i++)res[i]=l[i]+r[i];
        return res;
    }
    array<int,4>query(int v,int l,int r,int L,int R){
        if(R<l||r<L)return{0,0,0,0};
        if(L<=l&&r<=R)return t[v];
        int m=(l+r)/2;
        array<int,4>left=query(2*v+1,l,m,L,R);
        array<int,4>right=query(2*v+2,m+1,r,L,R);
        return combine(left,right);
    }
};
class Solution{
public:
    int maxDistance(string s,int k){
        int n=s.size();
        SegmentTree st(n);
        st.build(s,0,0,n-1);
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i+1;
            array<int,4>prefix=st.query(0,0,n-1,0,i);
            int e=prefix[0],w=prefix[1],n=prefix[2],s=prefix[3];
            int se=(e+s-w-n)+2*min(k,w+n);
            int sw=(w+s-e-n)+2*min(k,e+n);
            int nw=(w+n-e-s)+2*min(k,e+s);
            int ne=(e+n-w-s)+2*min(k,w+s);
            
            
            int bfp=max({ne,nw,se,sw});
            bfp=max(bfp,0);
            bfp=min(bfp,j);
            ans=max(ans,bfp);
        }
        return ans;
    }
};
