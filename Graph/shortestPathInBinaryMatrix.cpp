#include "../stdc++.h"
using namespace std;

// 0,1,0,0,0,0,
// 0,1,0,1,1,0,
// 0,1,1,0,1,0,
// 0,0,0,0,1,0,
// 1,1,1,1,1,0,
// 1,1,1,1,1,0

// (0,0)
// (1,0)
// (2,0)
// (3,1)
// (3,2)
// (3,3)
// (2,3)
// (1,2)
// (0,3)
// (0,4)
// (1,5)
// (2,5)
// (3,5)
// (4,5)
// (5,5)
// (0,5)
// (0,2)
// (3,0)

// int dfs(int row, int col, vector<vector<int> >& vis, vector<vector<int> >& grid, int& ans){
//     vis[row][col] = 1;
//     int n = grid.size();
//     if(row == n-1 && col == n-1) return 1;

//     int dx[8] = {1, 0, 1, 1, 0, -1, -1, -1};
//     int dy[8] = {1, 1, 0, -1, -1, 1, 0, -1};
//     int path = INT_MAX;
//     for(int i=0; i<8; i++){
//         int nr = row+dx[i];
//         int nc = col+dy[i];
//         if(nr<n && nr>-1 && nc<n && nc>-1){
//             if(grid[nr][nc] == 0 && !vis[nr][nc]){
//                 int res = dfs(nr, nc, vis, grid, ans);
//                 if(res != INT_MAX){
//                     path = min(res, path);
//                 }
//             }
//         }
//     }
//     if(path != INT_MAX){
//        ans = path+1;
//        return path+1; 
//     }
//     return path;
// }

int shortestPath(vector<vector<int> >& grid){
    int n = grid.size();
    vector<vector<int> > dist(n, vector<int>(n, 1e9));
    if(grid[0][0] != 0) return -1;
    int ans = 0;

    priority_queue<pair<int, pair<int,int> > , vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq;
    pq.push(make_pair(0, make_pair(0,0)));

    int dx[8] = {1, 0, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, 1, 0, -1};

    while(!pq.empty()){
        auto front = pq.top(); pq.pop();
        int distance = front.first;
        int row = front.second.first;
        int col = front.second.second;
        
        for(int i=0; i<8; i++){
            int nr = row+dx[i];
            int nc = col+dy[i];
            if(nr<n && nr>-1 && nc<n && nc>-1){
                if(grid[nr][nc] == 0){
                    if(distance + 1 < dist[nr][nc]){
                        dist[nr][nc] = distance + 1;
                        pq.push(make_pair(dist[nr][nc], make_pair(nr, nc)));
                    }
                }
            }
        }
    }

    return (dist[n-1][n-1] != 1e9) ? dist[n-1][n-1] + 1 : -1;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > grid(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            grid[i][j] = temp;
        }
    }
    cout<<shortestPath(grid);

    return 0;

}