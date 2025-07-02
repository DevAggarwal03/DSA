#include "../stdc++.h"
using namespace std;

int countPaths(int n, vector<vector<int> >& roads){
    vector<vector<pair<int,int> > > adj(n, vector<pair<int,int> >());
    for(auto it: roads){
        adj[it[0]].push_back(make_pair(it[1], it[2]));
        adj[it[1]].push_back(make_pair(it[0], it[2]));
    }

    vector<pair<int,int> > dist(n, make_pair(1e9,0));
    dist[0] = make_pair(0, 1);
    queue<pair<int,int> > q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        auto front = q.front(); q.pop();
        int distance = front.first;
        int node = front.second;
        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgWt = it.second;
            if(distance + edgWt < dist[adjNode].first){
                dist[adjNode].first = distance + edgWt;
                q.push(make_pair(dist[adjNode].first, adjNode));
                dist[adjNode].second += dist[node].second;
            }
        }
    }
    return dist[n-1].second;
}

int main(){


    return 0;

}