#include "../stdc++.h"
using namespace std;

vector<vector<int> > turn(vector<vector<int> > matrix){
    vector<vector<int> > ans(matrix[0].size(), vector<int>(matrix.size()));
    int i = matrix.size() - 1;
    int j = 0;

    for(int k=0; k<matrix[0].size(); k++){
        for(int l=0; l<matrix.size(); l++){
            if(i == 0 && j == matrix[0].size()-1){
                return ans;
            }
            ans[k][l] = matrix[i][j];
            if(i == 0){
                j++;
                i = matrix.size() - 1;
            }else{
                i--;
            }
        }
    }
}

int main(){
    int m;
    cin>>m;
    int n;
    cin>>n;
    vector<vector<int> > matrix(m, vector<int>(n));
    for(int i=0; i<m; i++){
       for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            matrix[i][j] = temp;
       } 
    }
    vector<vector<int> > ans = turn(matrix);
    cout<<"end of fun"<<endl;
    for(int i=0; i<ans.size(); i++){
       for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<"  ";
       } 
       cout<<endl;
    }


    return 0;

}