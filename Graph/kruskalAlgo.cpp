#include "../stdc++.h"
using namespace std;

class disjoingSet{
    vector<int> rank, parent;
    public:
        disjoingSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(node == parent[node]) return node;
            
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int ul_u = findUParent(u);
            int ul_v = findUParent(v);
            if(ul_v == ul_u) return;

            if(rank[ul_u] < rank[ul_v]){
                parent[ul_u] = ul_v;
            }else if(rank[ul_v] < rank[ul_u]){
                parent[ul_v] = ul_u;
            }else{
                parent[ul_v] = ul_u;
                rank[ul_u]++;
            }
        }
};


int kruskalAlgo(vector<vector<pair<int,int> > >& adj, int V){
    vector<vector<int> > edges;
    for(int i=0; i<V+1; i++){
        for(auto it: adj[i]){
            vector<int> temp;
            temp.push_back(it.second);
            temp.push_back(i);
            temp.push_back(it.first);
            edges.push_back(temp);
        }
    }
    sort(edges.begin(), edges.end());
    int sum = 0;
    disjoingSet ds(V);
    for(auto it: edges){
        if(ds.findUParent(it[1]) != ds.findUParent(it[2])){
            sum+=it[0];
            ds.unionByRank(it[1], it[2]);
        }
    }


    return sum;
}

int main(){

    int V, E;
    cin>>V>>E;
    vector<vector<pair<int,int> > > adj(V+1, vector<pair<int,int> >());
    for(int i=0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int sum = kruskalAlgo(adj, V);
    cout<<sum<<endl;

    return 0;

}