#include "../stdc++.h"
using namespace std;

vector<int> topologicalSort(int V, vector<int> adj[]){
    vector<int> indegree(V, 0);
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            indegree[adj[i][j]] += 1;
        }
    }
    queue<int> q;
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int front = q.front(); q.pop();
        for(int i=0; i<adj[front].size(); i++){
            int neighbour = adj[front][i];
            indegree[neighbour] -= 1;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
        ans.push_back(front);
    }

    return ans;
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
    
    vector<int> sortedArr = topologicalSort(n, adj);
    for(auto i: sortedArr){
        cout<<i<<" ";
    }
    return 0;
}