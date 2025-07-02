#include "../stdc++.h"
using namespace std;

bool detectCycleBFS(int V, vector<int> adj[]){
    vector<int> indegree(V, 0);
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> order;
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(int i=0; i<adj[front].size(); i++){
            indegree[adj[front][i]]--;
            if(indegree[adj[front][i]] == 0){
                q.push(adj[front][i]);
            }
        }
        order.push_back(front);
    }

    if(order.size() == V){
        return false;
    }

    return true;
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
    
    bool hasCycle = detectCycleBFS(n, adj);
    cout<<hasCycle;

    return 0;

}