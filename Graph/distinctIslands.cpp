#include "../stdc++.h"
using namespace std;

void bfsAndStore(int currRow, int currCol, vector<vector<int> >& vis, vector<vector<int> >& mat, set<vector<pair<int,int> > >& set){
    queue<pair<int,int> > q;
    int rows = vis.size();
    int cols = vis[0].size();
    q.push(make_pair(currRow, currCol));
    vector<pair<int, int> > temp;
    vis[currRow][currCol] = 1;
    temp.push_back(make_pair(0, 0));
    vector<int> dx; dx.push_back(1); dx.push_back(0); dx.push_back(-1); dx.push_back(0);
    vector<int> dy; dy.push_back(0); dy.push_back(1); dy.push_back(0); dy.push_back(-1);
    while(!q.empty()){
        auto front = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nr = front.first+dx[k];
            int nc = front.second+dy[k];
            if(nr<rows && nr>-1 && nc<cols && nc>-1 && mat[nr][nc] == 1 && !vis[nr][nc]){
                int relRow = front.first-nr;
                int relCol = front.second-nc;
                temp.push_back(make_pair(relRow, relCol));
                vis[nr][nc] = 1;
                q.push(make_pair(nr, nc));
            }
        }    
    }
    
    set.insert(temp);
}

int distinctIslands(vector<vector<int> > mat){
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int> > vis(rows, vector<int>(cols, 0));
    set<vector<pair<int, int> > > set;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(mat[i][j] == 1 && !vis[i][j]){
                bfsAndStore(i, j, vis, mat, set);
            }
        }
    }
    cout<<endl;
    for(auto i: set){
        for(auto j : i){
            cout<<"("<<j.first<<" "<<j.second<<") ";
        }
        cout<<endl;
    }
    return set.size();
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

    cout<<distinctIslands(grid);

    return 0;

}