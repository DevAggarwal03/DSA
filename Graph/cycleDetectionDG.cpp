#include "../stdc++.h"
using namespace std;

bool dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& pathVis){
    vis[node] = 1;
    pathVis[node] = 1;
    cout<<endl;
    cout<<node<<"->";
    for(int i=0; i<adj[node].size(); i++){
        cout<<adj[node][i]<<" ";
        if(!pathVis[adj[node][i]]){
            if(!vis[adj[node][i]]){
                bool res = dfs(adj[node][i], vis, adj, pathVis);
                if(res){
                    return true;
                }
            }else{
                continue;
            }
        }else{
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool detectCycleDFS(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    for(int i=0; i<V; i++){
        if(!vis[i]){
            bool hasCycle = dfs(i, vis, adj, pathVis);
            if(hasCycle) return true;
        }
    }
    return false;
}

int main(){
    int V;
    int E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<endl;
    for(int i=0; i<V; i++){
        cout<<i<<"->";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<detectCycleDFS(V, adj);
    return 0;
}