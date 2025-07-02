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

int removeStones(vector<vector<int> >& stones){
    int maxCol = 0;
    int maxRow = 0;
    for(auto it: stones){
        maxCol = max(maxCol, it[1]);
        maxRow = max(maxRow, it[0]);
    }

    disjointSet ds(maxRow + maxCol + 1);
    unordered_map<int,int> allStones;
    for(auto it: stones){
        int appRow = it[0];
        int appCol = it[1] + maxRow + 1;
        ds.uniounByRank(appRow, appCol);
        allStones[appRow] = 1;
        allStones[appCol] = 1;
    }
    int noOfComps = 0;
    // for(auto it: allStones){
    //     if(ds.findUParent(it.first) == it.first){
    //         noOfComps++;
    //     }
    // }
    for(auto it: stones){
        if(ds.findUParent(it[0]) == it[0]){
            noOfComps++;
        }
        if(ds.findUParent(it[1]) == it[0]){
            noOfComps++;
        }
    }
    return stones.size() - noOfComps;
}

int main(){


    return 0;

}