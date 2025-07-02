#include "../stdc++.h"
using namespace std;

// using binary search TC: O(mLog(n));

bool bs(vector<int> arr, int target){
    int s = 0, e = arr.size() - 1;
    int mid = (s + e) / 2;

    while(s <= e){
        if(arr[mid] == target){
            return true;
        }
        if(arr[mid] > target){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
        mid = (s + e)/2;
    }
    return false;
}

bool findInMatrix(vector<vector<int> > matrix, int target){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i=0; i<rows; i++){
        if(bs(matrix[i], target)){
            return true;
        }
    }
    return false;
}

//using diagnal traversal Tc: O(m + n);
bool diagnalTraversal(vector<vector<int> > matrix, int target){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int rowPtr = 0;
    int colPtr = cols - 1;

    while(rowPtr < rows && colPtr >=0){
        if(matrix[rowPtr][colPtr] > target){
            colPtr--;
        }else if(matrix[rowPtr][colPtr] < target){
            rowPtr++;
        }else{
            return true;
        }
    }

    return false;
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
    int target;
    cin>>target;
    bool ans = diagnalTraversal(matrix, target);
    cout<<ans<<endl;
}