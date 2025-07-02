#include "../stdc++.h"
using namespace std;

vector<vector<int> > foodFill(vector<vector<int> >& image, int sr, int sc, int color) {
    int orgColor = image[sr][sc];
    int rows = image.size();
    int cols = image[0].size();
    vector<int> dx; dx.push_back(1); dx.push_back(0); dx.push_back(-1); dx.push_back(0);
    vector<int> dy; dy.push_back(0); dy.push_back(1); dy.push_back(0); dy.push_back(-1);
    queue<pair<int,int> > q;
    q.push(make_pair(sr, sc));
    while(!q.empty()){
        pair<int,int> front = q.front(); q.pop();
        int row = front.first;
        int col = front.second;
        for(int i=0; i<4; i++){
            if(row+dx[i] < rows && row+dx[i] > -1 && col+dy[i] < cols && col+dy[i] > -1 && image[row+dx[i]][col+dy[i]] == orgColor){
                image[row+dx[i]][col+dy[i]] = color;
                q.push(make_pair(row+dx[i], col+dy[i]));
            }
        }
    }

    return image;
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
    int sr;
    cout<<"sr: "; cin>>sr;
    int sc;
    cout<<"sc: "; cin>>sc;
    int color;
    cout<<"color: "; cin>>color;
    vector<vector<int> > ans = foodFill(grid, sr, sc, color);
    cout<<endl;
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;

}