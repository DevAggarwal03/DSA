#include "../stdc++.h"
using namespace std;

void printMatrixDiag(vector<vector<int> > matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i = 0;
    int j = 0;
    for(int k = 0; k<matrix.size(); k++){
        while(i >= 0 && j < cols){
            cout<<matrix[i--][j++]<<" ";
        }
        j = 0;
        i = k+1;
    }
    for(int k = 1; k < matrix[0].size(); k++){
        j = k;
        i = matrix.size()-1;
        while(j < cols){
            cout<<matrix[i--][j++]<<" ";
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
    printMatrixDiag(matrix);
    return 0;

}