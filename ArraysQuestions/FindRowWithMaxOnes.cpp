#include "../stdc++.h"
using namespace std;

//using binary search TC: O(m*log(n))
int binary_search(vector<int> arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = (s + e) / 2;

    while(s < e){
        if(arr[mid] == 1){
            e = mid;
        }
        else{
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }

    if(arr[e] != 1){
        return arr.size();
    }
    return e;
}

int findRowWithMaxOnes(vector<vector<int> > matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int minIndex = n;
    int row = m;
    for(int i=0; i<m; i++){
        int firstOne = binary_search(matrix[i]);
        if(firstOne < minIndex){
            minIndex = firstOne;
            row = i;
        }
    }

    if(minIndex == n){
        return -1;
    }
    return row;
}

//using diagonal traversal from top right TC: O(m + n);

int diagonalTraversal(vector<vector<int> > matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int i = n-1;
    int j = 0;
    int maxRow = -1;
    for(; i>=0, j<m; i--,j++){
        if(matrix[j][i] == 1){
            maxRow = j;
        }
    }
    return maxRow;
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
    int ans = diagonalTraversal(matrix);
    cout<<ans<<endl;
}