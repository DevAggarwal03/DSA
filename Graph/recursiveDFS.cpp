#include "../stdc++.h"
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[]){
    vis[node] = 1;
    cout<<node<<" ";
    for(auto i : adj[node]){
        if(vis[i] != 1){
            dfs(i, vis, adj);
        }
    }
}

int main(){

   int n, m;
    cin>>n>>m;
    //1 based indexing
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    } 

    vector<int> vis(n, 0);
    vis[0] = 1;
    for(int i=0; i<n; i++){
        if(vis[i] != 1){
            dfs(i, vis, adj);
        }
    }
    return 0;

}