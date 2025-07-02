#include "../stdc++.h"
using namespace std;

void getAdj(vector<string>& words, vector<int> adj[]){
    int totalWords = words.size();
    int x = 0;
    for(int i=0; i<totalWords-1; i++){
        while(words[i][x] == words[i+1][x]){
            x++;
        }
        adj[words[i][x]-'a'].push_back(words[i+1][x]-'a');
    }
}

string findOrder(vector<string> &words, int K){
    vector<int> adj[K];
    // getAdj(words, adj);
    int x = 0;
    for(int i=0; i<words.size() - 1; i++){
        while(words[i][x] == words[i+1][x]){
            x++;
        }
        adj[words[i][x]-'a'].push_back(words[i+1][x]-'a');
        x = 0;
    }

    string ansString = "";

    vector<int> indegree(K, 0);
    for(int i=0; i<K; i++){
        for(int j=0; j<adj[i].size(); j++){
            int adjacent = adj[i][j];
            indegree[adjacent]++;
        }
    }
    queue<int> q;
    for(int i=0; i<K; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(int i=0; i<adj[front].size(); i++){
            int adjacent = adj[front][i];
            indegree[adjacent]--;
            if(indegree[adjacent] == 0){
                q.push(adjacent);
            }
        }
        ans.push_back(front);
    }
    if(ans.size() == K){
        for(auto i: ans){
            ansString = ansString + char(i + 'a');
        }
    }
    return ansString;
}

int main(){
    int n;
    cin>>n;
    vector<string> wordList(n);
    int K;
    cin>>K;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        wordList[i] = temp;
    }

    cout<<findOrder(wordList, K);

    return 0;

}