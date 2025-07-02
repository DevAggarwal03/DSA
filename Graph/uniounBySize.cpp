#include "../stdc++.h"
using namespace std;

class disjointSet{
    vector<int> size, parent;
    public:
        disjointSet(int n){
            size.resize(n+1);
            parent.resize(n+1);
            for(int i=0; i<n+1; i++){
                size[i] = 1;
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUParent(parent[node]);
        }

        void uniounBySize(int u, int v){
            int ul_u = findUParent(u);
            int ul_v = findUParent(v);
            if(ul_u == ul_v) return;
            if(size[ul_u] < size[ul_v]){
                parent[ul_u] = ul_v;
                size[ul_v] += size[ul_u];
            }else{
                parent[ul_v] = ul_u;
                size[ul_u] += size[ul_v];
            }
        }
};

int main(){

    disjointSet ds(7);
    ds.uniounBySize(1, 2);
    ds.uniounBySize(2, 3);
    ds.uniounBySize(4, 7);
    ds.uniounBySize(5, 6);
    if(ds.findUParent(5) == ds.findUParent(1)){
        cout<<"same \n";
    }else{
        cout<<"not same \n";
    }

    ds.uniounBySize(6, 3);

    if(ds.findUParent(5) == ds.findUParent(1)){
        cout<<"same \n";
    }else{
        cout<<"not same \n";
    }

    return 0;
}