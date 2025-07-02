#include "../stdc++.h"
using namespace std;

int minimumEffortPath(vector<vector<int> >& heights){
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<int> > minEffort(rows, vector<int>(cols, 1e9));
    minEffort[0][0] = 0;

    priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq;

    pq.push(make_pair(0, make_pair(0, 0)));

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!pq.empty()){
        auto front = pq.top(); pq.pop();
        int effort = front.first;
        int row = front.second.first;
        int col = front.second.second;

        for(int i=0; i<4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];
            if(nr<rows && nr>-1 && nc<cols && nc>-1 && max(effort, abs(heights[row][col] - heights[nr][nc])) < minEffort[nr][nc]){
                minEffort[nr][nc] = max(effort, abs(heights[row][col] - heights[nr][nc]));
                pq.push(make_pair(minEffort[nr][nc], make_pair(nr, nc)));
            }
        }
    }
    return minEffort[rows-1][cols-1];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > grid(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin>>temp;
            grid[i][j] = temp;
        }
    }
    cout<<minimumEffortPath(grid);

    return 0;

}