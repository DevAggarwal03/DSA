#include "../stdc++.h"
using namespace std;

class disjointSet{
    vector<int> rank, parent;
    public:
        disjointSet(int n){
            rank.resize(n, 0);
            parent.resize(n);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUParent(parent[node]);
        }

        void uniounByRank(int u, int v){
            int ul_u = findUParent(u);
            int ul_v = findUParent(v);
            if(ul_u == ul_v) return;
            if(rank[ul_u] < rank[ul_v]){
                parent[ul_u] = ul_v;
            }else if(rank[ul_u] > rank[ul_v]){
                parent[ul_v] = ul_u;
            }else{
                parent[ul_v] = ul_u;
                rank[ul_u]++;
            }
        }
};

vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
    int n = accounts.size();
    disjointSet ds(n);
    unordered_map<string, int> mp;
    for(int i=0; i<n; i++){
        for(int j=1; j<accounts[i].size(); j++){
            auto node = mp.find(accounts[i][j]);
            if(node != mp.end()){
                ds.uniounByRank(node->second, i);
            }
            mp.insert(make_pair(accounts[i][j], i));
        }
    }
    vector<vector<string> > ans(n, vector<string>());
    for(auto it: mp){
        int parent = ds.findUParent(it.second);
        ans[parent].push_back(it.first);
    }

    vector<vector<string> > mergedMail;
    for(int i=0; i<n; i++){
        if(ans[i].size() == 0) continue;
        sort(ans[i].begin(), ans[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it: ans[i]){
            temp.push_back(it);
        }
        mergedMail.push_back(temp);
        temp.clear();
    }    


    return mergedMail;
}

int main(){
    int n;
    cin>>n;
    vector<vector<string> > accounts(n, vector<string>());
    for(int i=0; i<n; i++){
        int b;
        cin>>b;
        for(int j=0; j<b; j++){
            string temp;
            cin>>temp;
            accounts[i].push_back(temp);
        } 
    }

    vector<vector<string> > ans = accountsMerge(accounts);
    for(auto a: ans){
        for(auto b: a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;

}