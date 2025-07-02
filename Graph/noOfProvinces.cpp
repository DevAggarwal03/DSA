#include "../stdc++.h"
using namespace std;

int findCircleNum(vector<vector<int> >& isConnected) {
    vector<bool> vis(isConnected.size(), false);
    
    int noOfProvinces = 0;
    for(int k=0; k<vis.size(); k++){
        if(!vis[k]){
            queue<int> q;
            q.push(k);
            vis[k] = true;
            while(!q.empty()){
                int front = q.front(); q.pop();
                for(int j=0; j<isConnected[front].size(); j++){
                    if(isConnected[front][j] == 1){
                        if(!vis[j]){
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }
            }
            noOfProvinces++;
        }
    }

    return noOfProvinces;
            
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > isConnected(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            isConnected[i][j] = temp;
        }
    }

    int ans = findCircleNum(isConnected); 
    cout<<endl;
    cout<<ans;

    return 0;

}