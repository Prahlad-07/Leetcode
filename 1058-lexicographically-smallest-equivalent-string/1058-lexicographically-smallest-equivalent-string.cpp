class DisjointSet{
    private:
        vector<int> rank;
    public:
        vector<char> parent;
        DisjointSet(){
            rank.resize(26);
            parent.resize(26);
            for(int i = 0; i < 26; i++){
                rank[i] = i;
                parent[i] = i + 'a';
            }
        }
        char findParent(char node){
            if(node == parent[node - 'a']) return node;
            return parent[node - 'a'] = findParent(parent[node - 'a']);
        }
        void unionByRank(char u, char v){
            if(u == v) return;
            char pu = findParent(u);
            char pv = findParent(v);
            if(pu == pv) return;
            if(rank[pu - 'a'] < rank[pv - 'a']){
                parent[pv - 'a'] = pu;
            } else if(rank[pv - 'a'] < rank[pu - 'a']){
                parent[pu - 'a'] = pv;
            }
        }
        // void parents(){
        //     for(int i = 0; i < 26; i++){
        //         char charA = 'a' + i;
        //         cout<<charA<<" -> "<<parent[i]<<endl;
        //     }
        // }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds;
        int n = s1.size();
        for(int i = 0; i < n; i++){
            char u = s1[i], v = s2[i];
            ds.unionByRank(u, v);
        }
        for(auto & ch : baseStr){
            ds.findParent(ch);
            ch = ds.parent[ch - 'a'];
        }
        return baseStr;
    }
};