#include "../stdc++.h"
using namespace std;

void dfs(int node, stack<int>& st, vector<vector<int> >& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            dfs(adjNode, st, adj, vis);
        }
    }
    st.push(node);
    return;
}

void dfs2(int node, vector<int>& vis, vector<vector<int> >& adj, vector<int>& temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            dfs2(adjNode, vis, adj, temp);
        }
    }
    return;
}

void sortEdges(int V, vector<vector<int> >& adj, stack<int>& st){
    vector<int> vis(V+1, 0);
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            dfs(i, st, adj, vis);
        }
    } 
}

vector<vector<int> > kosaraju(int V, vector<vector<int> >& adj){
    //sort //reverse edges //dfs

    //sort:
    stack<int> st;
    sortEdges(V, adj, st);

    //reversing edges:
    vector<vector<int> > rAdj(V+1);
    for(int v=1; v<= adj.size(); v++){
        for(int u=0; u<adj[v].size(); u++){
            rAdj[adj[v][u]].push_back(v);
        }
    }

    //dfs
    vector<vector<int> > ans; 
    vector<int> vis(V+1, 0);
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            vector<int> temp;
            dfs2(i, vis, rAdj, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}

int main(){
    int v, e;
    cin>>v>>e;
    vector<vector<int> > adj(v+1);
    for(int i=1; i<=e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<vector<int> > ans = kosaraju(v, adj);

    for(auto it: ans){
        for(auto a: it){
            cout<<a<<' ';
        }
        cout<<endl;
    }

    return 0;

}