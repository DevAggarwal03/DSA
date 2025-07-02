#include "../stdc++.h"
using namespace std;

vector<vector<int> > updateMatrix(vector<vector<int> >& mat){
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int> > vis(rows, vector<int>(cols));
    vector<vector<int> > dis(rows, vector<int>(cols));
    queue<pair<pair<int, int> , int> > q;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(mat[i][j] == 0){
                q.push(make_pair(make_pair(i, j), 0));
            }
        }
    }
    vector<int> dx; dx.push_back(1); dx.push_back(0); dx.push_back(-1); dx.push_back(0);
    vector<int> dy; dy.push_back(0); dy.push_back(1); dy.push_back(0); dy.push_back(-1);
    while(!q.empty()){
        auto front = q.front();
        int row = front.first.first;
        int col = front.first.second;
        int lv = front.second;
        q.pop();
        dis[row][col] = lv;
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            if(row+dx[i]>-1 && row+dx[i]<rows && col+dy[i]<cols && col+dy[i]>-1 && !vis[row+dx[i]][col+dy[i]]){
                vis[row+dx[i]][col+dy[i]] = 1;
                if(mat[row+dx[i]][col+dy[i]] == 1){
                    q.push(make_pair(make_pair(row+dx[i], col+dy[i]), lv+1));
                }
            }
        }
    }

    return dis;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin>>temp;
            mat[i][j] = temp;  
        }   
    }

    vector<vector<int> > ans = updateMatrix(mat);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;

}