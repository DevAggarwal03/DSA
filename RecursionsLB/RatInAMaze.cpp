#include "../stdc++.h"

using namespace std;

bool isSafe(int newX, int newY, vector<vector<int> > visited, int n, vector<vector<int> > m){
    if(newX >= 0 && newX <= n-1 && newY >= 0 && newY <= n-1 && visited[newX][newY] == 0 && m[newX][newY] == 1){
        return true;
    }else return false;
}

void solve(vector<vector<int> > m, int n, vector<string>& ans, vector<vector<int> > visited, string path, int locX, int locY){
    if(locX == n - 1 && locY == n - 1){
        ans.push_back(path);
        return;
    }

    //down
    int newX = locX + 1;
    int newY = locY;
    if(isSafe(newX, newY, visited, n, m)){
        path.push_back('D');
        visited[newX][newY] = 1;
        solve(m, n, ans, visited, path, newX, newY);
        // visited[newX][newY] = 0;
        path.pop_back();
    }

    //left
    newX = locX;
    newY = locY - 1;
    if(isSafe(newX, newY, visited, n, m)){
        path.push_back('L');
        visited[newX][newY] = 1;
        solve(m, n, ans, visited, path, newX, newY);
        // visited[newX][newY] = 0;
        path.pop_back();
    }

    //right
    newX = locX;
    newY = locY + 1;
    if(isSafe(newX, newY, visited, n, m)){
        path.push_back('R');
        visited[newX][newY] = 1;
        solve(m, n, ans, visited, path, newX, newY);
        // visited[newX][newY] = 0;
        path.pop_back();
    }

    //up
    newX = locX - 1;
    newY = locY;
    if(isSafe(newX, newY, visited, n, m)){
        path.push_back('U');
        visited[newX][newY] = 1;
        solve(m, n, ans, visited, path, newX, newY);
        // visited[newX][newY] = 0;
        path.pop_back();
    }

}

vector<string > WaysToGetToTheEnd(vector<vector<int> >& m){
    vector<string> ans;
    if(m[0][0] == 0){
        return ans;
    }

    vector<vector<int> > visited = m;
    int n = m.size();
    string path = "";

    int locX = 0;
    int locY = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }
    visited[0][0] = 1;

    solve(m, n, ans, visited, path, locX, locY);

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > maze(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            maze[i][j] = x;
        }
    }

    vector<string > ways = WaysToGetToTheEnd(maze);
    cout<<endl;
    for(int i=0; i<ways.size(); i++){
        for(int j=0; j<ways[i].size(); j++){
            cout<<ways[i][j]<<" ";
        }
        cout<<endl;
    }
}