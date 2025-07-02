#include "../stdc++.h"
using namespace std;

vector<int> dijikstreaSet(int V, int s, vector<pair<int,int> > adj[]){
    set<pair<int,int> > st;
    vector<int> dist(V, 1e9);
    st.insert(make_pair(0, s));
    dist[s] = 0;
    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int distance = it.first;
        st.erase(it);
        for(auto neighbour : adj[node]){
            int adjNode = neighbour.first;
            int edgWt = neighbour.second;
            if(distance + edgWt < dist[adjNode]){
                //erasing the previous entry since new one is going to be added
                if(dist[adjNode] != 1e9){
                    st.erase(make_pair(dist[adjNode], adjNode));
                }

                dist[adjNode] = distance + edgWt;
                st.insert(make_pair(dist[adjNode], adjNode));
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
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    cin>>s;
    vector<int> dist = dijikstreaSet(V, s, adj);
    for(auto it: dist){
        cout<<it<<" ";
    }

    return 0;

}