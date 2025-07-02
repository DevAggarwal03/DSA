#include "../../stdc++.h";

using namespace std;

bool isPossible(int arr[], int students, int mid, int size){
    int student = 1;
    int pages = 0;
    for(int i=0; i<size; i++){
        // cout<<pages<<endl;
        if(pages + arr[i] <= mid){
            pages += arr[i];
        }else{
            student++;
            if(student > students || arr[i] > mid){
                return false;
            }
            pages = arr[i];
        }
    }
    return true;
}

void bookAllocation(int arr[], int students, int start, int end, int size, int& ans){
    int mid = (start + end) / 2;
    if(start > end){
        return;
    }

    if(isPossible(arr, students, mid, size)){
        ans = mid;
        return bookAllocation(arr, students, start, mid - 1, size, ans);
    }else{
        return bookAllocation(arr, students, mid + 1, end, size, ans);
    }
}

int main(){
    int students;
    cin>>students;

    int books;
    cin>>books;

    // int m = books;

    int arr[books];

    for(int i=0; i<books; i++){
        cin>>arr[i];
    }

    int end = 0;
    for(int i=0; i<books; i++){
        end += arr[i];
    }

    cout<<end<<endl;
    int ans = 0;
    bookAllocation(arr, students, 0, end, books, ans);

    cout<<ans<<endl;

    return 0;
}