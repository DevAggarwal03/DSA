#include "../stdc++.h"
using namespace std;

vector<int> shortestPath(int src, int V, int E, vector<vector<int> >& edges){
    vector<int> adj[V];
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(auto neighbour : adj[front]){
            if(dist[front] + 1 < dist[neighbour]){
                dist[neighbour] = dist[front] + 1;
                q.push(neighbour);
            }
        }
    }
    return dist;
}

int main(){
    int src, V, E;
    cin>>V>>E;
    vector<vector<int> > edges(E, vector<int>(2, 0));
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
    }
    cin>>src;
    vector<int> distVec = shortestPath(src, V, E, edges);
    
    for(auto i: distVec){
        if(i == INT_MAX){
            cout<<"INF ";
        }else{
            cout<<i<<" ";
        }
    }

    return 0;
}