#include "../stdc++.h"
using namespace std;

class disjointSet{
    vector<int> size, parent;
    public:
        disjointSet(int n){
            size.resize(n+1);
            parent.resize(n+1);
            for(int i=0; i<n+1; i++){
                size[i] = 1;
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUParent(parent[node]);
        }

        void uniounBySize(int u, int v){
            int ul_u = findUParent(u);
            int ul_v = findUParent(v);
            if(ul_u == ul_v) return;
            if(size[ul_u] < size[ul_v]){
                parent[ul_u] = ul_v;
                size[ul_v] += size[ul_u];
            }else{
                parent[ul_v] = ul_u;
                size[ul_u] += size[ul_v];
            }
        }
};

int numProvinces(vector<vector<int>> adj, int V) {
    disjointSet ds(V);
    vector<pair<int,int>> edges;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i != j && adj[i][j] == 1){
                edges.push_back(make_pair(i+1, j+1));
            }
        }
    }
    
    for(auto it: edges){
        if(ds.findUParent(it.first) != ds.findUParent(it.second)){
            ds.uniounBySize(it.first, it.second);
        }
    }
    
    unordered_set<int> st;
    for(int i=1; i<=V; i++){
        int parent = ds.findUParent(i);
        st.insert(parent);
    }
    
    return st.size();
}

int main(){
    

    return 0;

}