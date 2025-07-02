#include "../stdc++.h"
using namespace std;

bool bfs(int node, vector<int>& colorMatrix, vector<vector<int> >& graph){
    queue<int> q;
    q.push(node);
    colorMatrix[node] = 0;
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(int i=0; i<graph[front].size(); i++){
            int neighbour = graph[front][i];
            if(colorMatrix[neighbour] == -1){
                if(colorMatrix[front] == 1){
                    colorMatrix[neighbour] = 0; 
                }else{
                    colorMatrix[neighbour] = 1;
                }
                q.push(neighbour);
            }else if(colorMatrix[neighbour] == colorMatrix[front]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int> >& graph){
    vector<int> colorMatrix(graph.size(), -1);
    for(int i=0; i<colorMatrix.size(); i++){
        if(colorMatrix[i] == -1){
            int ans = bfs(i, colorMatrix, graph);
            if(!ans){
                return false;
            }
        }
    }
    return true;
}

int main(){


    return 0;

}