#include "../stdc++.h"

using namespace std;

int sum(vector<int>& vec){
    int sum = 0;
    for(int i=0; i<vec.size(); i++){
        sum += vec[i];
    }
    return sum;
}

bool isPossible(int vec[], int size, int students, int mid){
    int student = 1;
    int pageSum = 0;

    for(int i=0; i<size; i++){
        if(pageSum + vec[i] <= mid){
            pageSum += vec[i];
        }else{
            student += 1;
            if(student >= students || vec[i] > mid){
                return false;
            }
            pageSum = vec[i];
        }
    }

    return true;
}

// int bookAllocation(vector<int>& vec, int students){
//     int s = 0;
//     int e = sum(vec);
//     int m = (s + e) / 2;
//     int ans = -1;
//     while(s < e){
//         if(isPossible(vec, students, m)){
//             ans = m;
//             e = m - 1;
//         }else{
//             s = m + 1;
//         }
//         m = (s + e) / 2;
//     }
//     return ans;
// }

int bookAllocation(int arr[], int students, int start, int end, int size){
    int mid = (start + end) / 2;

    if(start > end){
        return end;
    }
    
    if(isPossible(arr, size, students, mid)){
        return bookAllocation(arr, students, start, mid, size);
    }else{
        return bookAllocation(arr, students, mid + 1, end, size);
    }
}

int main(){
    int students;
    cin>>students;

    int books;
    cin>>books;

    // int m = books;

    int vec[books];

    for(int i=0; i<books; i++){
        cin>>vec[i];
    }

    int end = 0;
    for(int i=0; i<books; i++){
        end += vec[i];
    }

    cout<<bookAllocation(vec, students, 0, end, books)<<endl;

    return 0;
}