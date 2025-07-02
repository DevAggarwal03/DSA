#include "../stdc++.h"
using namespace std;

bool dfs(int node, vector<vector<int> >& graph, vector<int>& ans, vector<int>& pathVis, vector<int>& vis){
    vis[node] = 1;
    pathVis[node] = 1;
    int result = true;
    for(int i=0; i<graph[node].size(); i++){
        if(!vis[graph[node][i]]){
            int res = dfs(graph[node][i], graph, ans, pathVis, vis);
            result = result && res;
        }else if(!pathVis[node]){
            ans.push_back(node);
        }
    }
    if(result){
        ans.push_back(node);
    }
    pathVis[node] = 0;
    return result; 
}

vector<int> eventualSafeNodes(vector<vector<int> >& graph){
    int V = graph.size();
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> ans;

    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, graph, ans, pathVis, vis);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main(){


    return 0;

}