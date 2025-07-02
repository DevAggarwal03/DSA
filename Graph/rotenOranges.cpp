#include "../stdc++.h"
using namespace std;

int orangesRotting(vector<vector<int> >& grid) {
    //finding oranges:
    vector<pair<int, int> > posOf2;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid.size(); j++){
            if(grid[i][j] == 2){
                posOf2.push_back(make_pair(i, j));            
            }
        }
    }
    
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > vis(n, vector<int>(m, false));
    queue<pair<int, int> > q;
    for(auto i : posOf2){
        q.push(i);
        vis[i.first][i.second] = 1;
    }
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            pair<int,int> front = q.front(); q.pop();
            int row = front.first, col = front.second;
            if(row+1 < n){
                if(grid[row+1][col] == 1){
                    grid[row+1][col] = 2;
                    q.push(make_pair(row+1, col));
                }
                vis[row+1][col] = 1;
            }
            if(row-1 > -1){
                if(grid[row-1][col] == 1){
                    grid[row-1][col] = 2;
                    q.push(make_pair(row-1, col));
                }
                vis[row-1][col] = 1;
            }
            if(col+1 < m){
                if(grid[row][col+1] == 1){
                    grid[row][col+1] = 2;
                    vis[row][col+1] = 1;
                }
                q.push(make_pair(row, col+1));
            }
            if(col-1 > -1){
                if(grid[row][col-1] == 1){
                    grid[row][col-1] = 2;
                    q.push(make_pair(row, col-1));
                }
                vis[row][col-1] = 1;
            }
        }
        if(!q.empty()) time++;
    }
    // cout<<"vis: "<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] != 1 && grid[i][j] == 1){
                time = -1;
            }
        }
    }
    
    return time;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int> > grid(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin>>temp;
            grid[i][j] = temp;
        }
    }

    int ans = orangesRotting(grid);
    cout<<endl<<ans<<endl;

    return 0;

}