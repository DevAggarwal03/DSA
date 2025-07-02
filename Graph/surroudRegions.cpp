#include "../stdc++.h"
using namespace std;

// void dfs(int i, int j,unordered_map<pair<int,int>, bool> zeroMap, int rows, int cols, vector<vector<char> >& board){
//     zeroMap[make_pair(i,j)] = true;
//     vector<int> dx = {1, 0, -1, 0};
//     vector<int> dy = {0, 1, 0, -1};
//     for(int k=0; k<4; k++){
//         int nr = i+dx[k];
//         int nc = i+dy[k];
//         if(nr>-1 && nr<rows && nc>-1 && nc<cols && board[nr][nc] == 'O' && !zeroMap[make_pair(nr, nc)]){
//             dfs(nr, nc, zeroMap, rows, cols, board);
//         }
//     }
// }

void dfs(int i, int j, vector<vector<int> > vis, vector<vector<char> >& board){
    vis[i][j] = 1;
    int rows = vis.size();
    int cols = vis[0].size();
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int k=0; k<4; k++){
        int nr = i+dx[k];
        int nc = i+dy[k];
        if(nr>-1 && nr<rows && nc>-1 && nc<cols && board[nr][nc] == 'O' && !vis[nr][nc]){
            dfs(nr, nc, vis, board);
        }
    }
    
}

void solve(vector<vector<char> >& board){
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int> > vis(rows, vector<int>(cols, 0));
    for(int i = 0; i<rows; i++){
        if(board[i][0] == 'O' && !vis[i][0]){
            dfs(i, 0, vis, board);
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(board[i][j] == 'O' && !vis[i][j]){
                board[i][j] = 'X';
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char> > board(n, vector<char>(m, 'O'));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char temp;
            cin>>temp;
            board[i][j] = temp;  
        }   
    }

    solve(board);
    for(auto i: board){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;

}