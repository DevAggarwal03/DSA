#include "../stdc++.h"
using namespace std;

pair<vector<pair<int,int> >, int> primsAlgo(vector<vector<pair<int,int> > >& adj, int V, int s){
    vector<pair<int,int> > MST;
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
    pq.push(make_pair(0, make_pair(0, -1))); 
    vector<int> vis(V, 0);
    int sum = 0;
    while(!pq.empty()){
        auto front = pq.top(); pq.pop();
        int wt = front.first;
        int node = front.second.first;
        int parent = front.second.second;
        if (vis[node]) continue; 
        vis[node] = 1;
        if(parent != -1){
            MST.push_back(make_pair(parent, node));
        }
        sum += wt;
        for(auto neighbour: adj[node]){
            int adjNode = neighbour.first;
            int edgWt = neighbour.second;
            if(!vis[adjNode]){
                pq.push(make_pair(edgWt, make_pair(adjNode, node)));
            }
        }
    }

    return make_pair(MST, sum);
}

int main(){
    int V, E;
    cin>>V>>E;
    vector<vector<pair<int,int> > > adj(V, vector<pair<int,int> >());
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int s;
    cin>>s;
    auto ans = primsAlgo(adj, V, s);
    for(auto it: ans.first){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl<<"sum: "<<ans.second;

    return 0;

}