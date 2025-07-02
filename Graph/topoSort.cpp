#include "../stdc++.h"
using namespace std;

void dfs(int node, stack<int>& st, int V, vector<int> adj[], vector<int>& vis){
    vis[node] = 1;
    for(int i=0; i<adj[node].size(); i++){
        int neighbour = adj[node][i];
        if(!vis[neighbour]){
            dfs(neighbour, st, V, adj, vis);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    stack<int> st;
    vector<int> ans;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, st, V, adj, vis);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return  ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    //1 based indexing
    vector<int> adj[n];
   
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    vector<int> sortedArr = topologicalSort(n, adj);
    for(auto i: sortedArr){
        cout<<i<<" ";
    }
    return 0;

}