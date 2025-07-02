#include "../stdc++.h"
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int,int> > adj[n];
    for(auto it: flights){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back(make_pair(v,w));
    }
    int ans = INT_MAX;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > pq;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    pq.push(make_tuple(0, src, 0));
    while(!pq.empty()){
        auto front = pq.top(); pq.pop();
        int distance = get<0>(front);
        int node = get<1>(front);
        int lv = get<2>(front);
        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            if(distance + edgeWt < dist[adjNode]){
                dist[adjNode] = distance + edgeWt;
                lv++;
                if(adjNode == dst && lv <= k){
                    ans = min(dist[adjNode], ans);
                }
            }
        }
    }        
    if(ans != INT_MAX) return ans;
    return -1;
}

int main(){
    

    return 0;

}