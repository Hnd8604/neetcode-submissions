class Solution {
    int parent[1000], size[1000];
    private:
     void union_(int a, int b){
        a = find(a);
        b = find(b);
        if( a!=b ){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
        }
    }
    private:
     int find(int v){
        if(v == parent[v]){
            return v;
        }
        return parent[v] = find(parent[v]);
    }
    private:
     void make_set(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        make_set(n);
        for(const auto& edge : edges){
            union_(edge[0], edge[1]);
        }
        for(int i = 0; i < n; i++){
            if(size[i] > 0) res++;
        }
        return res;
        
    }
};
