#include "../stdc++.h"
using namespace std;

vector<int> dijikstra(int V, int s, vector<pair<int,int> > adj[]){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0, s));
    vector<int> dist(V, 1e9);
    dist[s] = 0;
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto neighbour: adj[node]){
            if(distance + neighbour.second < dist[neighbour.first]){
                dist[neighbour.first] = distance + neighbour.second;
                pq.push(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main(){
    int V, E, s;
    cin>>V>>E;
    vector<pair<int,int> > adj[V];
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u, w));
    }
    cin>>s;
    vector<int> dist = dijikstra(V, s, adj);
    for(auto it: dist){
        cout<<it<<" ";
    }

    return 0;

}