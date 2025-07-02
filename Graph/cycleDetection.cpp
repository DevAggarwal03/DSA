#include "../stdc++.h"
using namespace std;

bool detectCycle(int node, int parent, vector<int> adj[], vector<int>& vis){
    vis[node] = 1;
    for(auto i: adj[node]){
        if(vis[i] != 1){
            bool res = detectCycle(i, node, adj, vis);
            if(res){
                return true;
            }
        }else if(i != parent){
            return true;
        }
    }

    return false;
}

bool bfsDetectCycle(int V, vector<int>& vis, vector<int> adj[]){
    queue<pair<int, int> > q;
    q.push(make_pair(0, -1));
    vis[0] = 1;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int parent = front.second;
        int node = front.first;
        for(int i=0; i<adj[node].size(); i++){
            if(!vis[adj[node][i]]){
                vis[adj[node][i]] = 1;
                q.push(make_pair(adj[node][i], node));
            }else if(parent != adj[node][i]){
                return true;
            }
        }
    }
    return false;
}

bool bfsCycleDetection(int V, vector<vector<int> >& edges){
   vector<int> adj[V];
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(V, 0);
    for(int i=0; i<vis.size(); i++){
        if(!vis[i]){
            int hasCycle = bfsDetectCycle(V, vis, adj);
            if(hasCycle)return true;
        }
    }
    
    return false;
}

bool isCycle(int V, vector<vector<int> >& edges) {
    vector<int> adj[V];
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(V, 0);
    int hasCycle = false;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            // hasCycle = detectCycle(i, -1, adj, vis);
            hasCycle = bfsCycleDetection(V, edges);
            if(hasCycle) return true;
        }
    }
    return false;
}

int main(){
    int V;
    int E;
    cin>>V>>E;
    vector<vector<int> > edges(E, vector<int>(2));
    for(int i = 0; i<E; i++){
        int u,v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    cout<<isCycle(V, edges);

    return 0;

}