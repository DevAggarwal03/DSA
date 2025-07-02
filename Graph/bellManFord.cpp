#include "../stdc++.h"
using namespace std;

vector<int> bellmanFord(int V, int E, vector<vector<int> >& edges, int s){
    vector<int> dist(V, 1e9);
    dist[s] = 0;
    for(int i=0; i<V-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u] != 1e9 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if(dist[u] != 1e9 && dist[u] + w < dist[v]){
            return vector<int>(1, -1);
        }
    }

    return dist;
}

int main(){
    int V;
    int E;
    cin>>V>>E;
    vector<vector<int> > edges(E, vector<int>(3));
    for(int i = 0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }
    int s;
    cin>>s;
    vector<int> ans = bellmanFord(V, E, edges, s);
    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;

}