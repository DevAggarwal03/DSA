#include "../stdc++.h"
using namespace std;

class disjointSet{
    vector<int> size, parent;
    public:
        disjointSet(int n){
            size.resize(n, 1);
            parent.resize(n);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUParent(parent[node]);
        }

        int getSize(int parent){
            return size[parent];
        }

        void uniounByRank(int u, int v){
            int ul_u = findUParent(u);
            int ul_v = findUParent(v);
            if(ul_u == ul_v) return;
            if(size[ul_u] < size[ul_v]){
                parent[ul_u] = ul_v;
                size[ul_v] += size[ul_u];
            }else{
                parent[ul_v] = ul_u;
                size[ul_u] += size[ul_v];
            }
        }
};

void bfsUnion(int row, int col, disjointSet& ds, vector<vector<int> >& grid, int dx[], int dy[], vector<vector<int> >& vis){
    queue<pair<int,int> > q;
    int rows = grid.size();
    int cols = grid[0].size();
    q.push(make_pair(row, col));
    vis[row][col] = 1;
    while(!q.empty()){
        auto front = q.front(); q.pop();
        int node = (front.first*cols) + front.second;
        for(int i=0; i<4; i++){
            int nr = front.first + dx[i]; 
            int nc = front.second + dy[i]; 
            if(nr<rows && nr>-1 && nc<cols && nc>-1 && grid[nr][nc] == 1 && vis[nr][nc] != 1){
                int nextNode = (nr*cols) + nc;
                ds.uniounByRank(node, nextNode);
                vis[nr][nc] = 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int largestIsland(vector<vector<int> >& grid){
    int rows = grid.size();
    int cols = grid[0].size();
    disjointSet ds(rows*cols);
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int> > vis(rows, vector<int>(cols, 0));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                bfsUnion(i, j, ds, grid, dx, dy, vis);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<rows; i++){ 
        for(int j=0; j<cols; j++){
            if(grid[i][j] == 0){
                unordered_set<int> st;
                int loAns = 0;
                for(int k=0; k<4; k++){
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if(nr<rows && nc<cols && nc>-1 && nr>-1 && grid[nr][nc] == 1){
                        int up = ds.findUParent((nr*cols) + nc);
                        bool consideredAlready = false;
                        st.insert(up);
                    }
                }
                for(auto it: st){
                    int size = ds.getSize(it);
                    loAns += size;
                }
                ans = max(ans, loAns + 1);
            }
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > grid(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin>>temp;
            grid[i][j] = temp;
        }
    }
    int ans = largestIsland(grid);
    cout<<ans;

    return 0;

}