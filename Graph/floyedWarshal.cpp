#include "../stdc++.h"
using namespace std;

vector<vector<int> > floyedWarshal(vector<vector<int> >& edges, int V, int E){

    vector<vector<int> > cost(V, vector<int>(V, 1e9));
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        cost[u][v] = w;
    }
    for(int i=0; i<V; i++){
        cost[i][i] = 0;
    }

    for(int i=0; i<V; i++){
        for(int row=0; row<cost.size(); row++){
            for(int col=0; col<cost[row].size(); col++){
                cost[row][col] = min(cost[row][col], cost[row][i]+cost[i][col]);
            }
        }
    }
    
    for(int i=0; i<V; i++){
        if(cost[i][i] < 0){
            cout<<"negative cycle exists ";
        }
    }
    cout<<endl;

    return cost;

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

    vector<vector<int> > ans = floyedWarshal(edges, V, E);

    for(auto it: ans){
        for(auto el: it){
            if(el == 1e9){
                cout<<"INF ";
            }else{
                cout<<el<<" ";
            }
        }
        cout<<endl;
    }

    return 0;

}