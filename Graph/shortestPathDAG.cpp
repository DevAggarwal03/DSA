#include "../stdc++.h"
using namespace std;

void dfs(int node, stack<int>& st, vector<pair<int,int> > adj[], vector<int>& vis){
    vis[node] = 1;
    for(int i=0; i<adj[node].size(); i++){
        int neighbour = adj[node][i].first;
        if(!vis[neighbour]){
            dfs(neighbour, st, adj, vis);
        }
    }
    st.push(node);   
}

vector<int> shortestPathDAG(int src, int V, int E, vector<vector<int> >& edges){
    vector<pair<int,int> > adj[V];
    for(int i=0; i<E; i++){
        adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
    }

    stack<int> st;
    vector<int> vis(V);
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, st, adj, vis);
        }
    }

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    while(!st.empty()){
        int front = st.top(); st.pop();
        int distFront = dist[front];
        if(distFront == INT_MAX) continue;
        for(int i=0; i<adj[front].size(); i++){
            pair<int,int> neighbour = adj[front][i];
            dist[neighbour.first] = min(dist[neighbour.first], distFront + neighbour.second);
        }
    }

    return dist;
}

int main(){
    int V, E;
    cin>>V>>E;
    
    vector<vector<int> > edges(E, vector<int>(3,0));
    for(int i=0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    int src;
    cin>>src;

    vector<int> disVec = shortestPathDAG(src, V, E, edges);
    cout<<endl;
    for(auto i: disVec){
        if(i == INT_MAX){
            cout<<"INF ";
        }else{
            cout<<i<<" ";
        }
    }
    return 0;

}