#include "../stdc++.h"
using namespace std;

int cntCoponents(vector<int> adj[], int n, int start){
    vector<int> vis(n+1, 0);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            start = i;
            queue<int> q;
            q.push(start);
            vis[start] = 1;
            while(!q.empty()){
                int element = q.front();
                q.pop();
                vis[adj[element][i]] = 1;
                for(int i=0; i<adj[element].size(); i++){
                    if(vis[adj[element][i]] != 1){
                        q.push(adj[element][i]);
                    }
                }
            }
            cnt++;
        }
    }
    return cnt;

}

vector<int> dfs(int N, int start, vector<vector<int> >& adj){
    stack<int> st;
    vector<int> vis(N+1, 0);
    vector<int> ans;
    vis[start] = 1;
    ans.push_back(start);
    st.push(start);
    while(!st.empty()){
        int top = st.top(); st.pop();
        for(int i=0; i<adj[top].size(); i++){
            if(!vis[adj[top][i]]){
                ans.push_back(adj[top][i]);
                vis[adj[top][i]] = 1;
                st.push(adj[top][i]);
            }
        }
    }

    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    //1 based indexing
    // vector<int> adj[n+1];
    vector<vector<int> > adj(n + 1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        //undirected
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }


    // int ans = cntCoponents(adj, n, 1);
    vector<int> ans = dfs(n, 1, adj);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}