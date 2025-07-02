#include "../stdc++.h"
using namespace std;

class disjointSet{
    vector<int> rank, parent;
    public:
        disjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
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

int main(){

    disjointSet ds(7);
    ds.uniounByRank(1, 2);
    ds.uniounByRank(2, 3);
    ds.uniounByRank(4, 7);
    ds.uniounByRank(5, 6);
    if(ds.findUParent(5) == ds.findUParent(1)){
        cout<<"same \n";
    }else{
        cout<<"not same \n";
    }

    ds.uniounByRank(6, 3);

    if(ds.findUParent(5) == ds.findUParent(1)){
        cout<<"same \n";
    }else{
        cout<<"not same \n";
    }

    return 0;

}