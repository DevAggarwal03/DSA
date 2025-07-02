#include "../stdc++.h"
using namespace std;

class disjointSet{
    vector<int> rank, parent;
    public:
        disjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUParent(parent[node]);
        }

        void uniounByRank(int u, int v){
            int ul_u = findUParent(u);
            int ul_v = findUParent(v);
            if(ul_u == ul_v) return;
            if(rank[ul_u] < rank[ul_v]){
                parent[ul_u] = ul_v;
            }else if(rank[ul_u] > rank[ul_v]){
                parent[ul_v] = ul_u;
            }else{
                parent[ul_v] = ul_u;
                rank[ul_u]++;
            }
        }
};

vector<int> numOfIslands(int n, int m, vector<vector<int> > &operators) {
    vector<vector<int> > world(n, vector<int>(m, 0));
    disjointSet ds((n-1)*m + m);
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<int> ans;
    for(int i=0; i<operators.size(); i++){
        int row = operators[i][0];
        int col = operators[i][1];
        if(world[row][col] == 1){
            ans.push_back(ans[ans.size() - 1]);
            continue;
        }
        world[row][col] = 1;
        int node = (row*m) + col;
        for(int i=0; i<4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];
            if(nr<n && nr>-1 && nc<m && nc>-1 && world[nr][nc] == 1){
                int newNode = (nr*m) + nc;
                ds.uniounByRank(node, newNode);
            }
        }
        int comp = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(world[i][j] == 1 && ds.findUParent((i*m) + j) == (i*m) + j){
                    comp++;
                }
            }
        }
        ans.push_back(comp);
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    int t;
    cin>>t;
    vector<vector<int> > operators(t, vector<int>(2));
    for(int i=0; i<t; i++){
        int u, v;
        cin>>u>>v;
        operators[i][0] = u;
        operators[i][1] = v;
    }

    vector<int> ans = numOfIslands(n, m, operators);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;

}