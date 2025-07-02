#include "../stdc++.h"
using namespace std;

void printMatrixSpirally(vector<vector<int> > matrix){
   int rows = matrix.size();
   int cols = matrix[0].size(); 
   int l = -1, r = cols, t = -1, b = rows;
   int i = 0, j = 0;
   bool stop = false;
   string direction = "R";
   while(!stop){
        if(0 < j+1 && direction == "R"){
            if(j+1 < r){
                cout<<matrix[i][j++]<<" ";
            }else if(j+1 == r){
                // cout<<matrix[i][j]<<" ";
                direction = "D";
                t++;
            }
        }
        if(0<i+1 && direction == "D"){
            if(i+1 < b){
                cout<<matrix[i++][j]<<" ";
            }else if(i+1 == b){
                // cout<<matrix[i][j]<<" ";
                direction = "L";
                r--;
            }
        }
        if(j-1 < cols - 1 && direction == "L"){
            if(j-1 > l){
                cout<<matrix[i][j--]<<" ";
            }else if(j-1 == l){
                // cout<<matrix[i][j]<<" ";
                direction = 'U';
                b--;
            }
        }
        if(i-1 < rows - 1 && direction == "U"){
           if(i-1 > t){
                cout<<matrix[i--][j]<<" ";
           }else if(i-1 == t){
                // cout<<matrix[i][j]<<" ";
                direction = "R";
                l++;
           } 
        } 
        if(direction == "L"){
            if(j-1 == l && i-1 == t && i+1 == b){
                cout<<matrix[i][j]<<" ";
                stop = true;
            }
        }
        if(direction == "D"){
            if(j+1 == r && j-1 == l && i+1 == b){
                cout<<matrix[i][j]<<" ";
                stop = true;
            }
        }
        if(direction == "R"){
            if(i+1 == b && i-1 == t && j+1 == r){
                cout<<matrix[i][j]<<" ";
                stop = true;
            }
        }
        if(direction == "U"){
            if(i-1 == t && j-1 == l && j+1 == r){
                cout<<matrix[i][j]<<" ";
                stop = true;
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
    printMatrixSpirally(matrix);
}