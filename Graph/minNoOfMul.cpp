#include "../stdc++.h"
using namespace std;

int minNoOfMul(vector<int>& numbers, int st, int target){
    int mod = 100000;
    queue<pair<int,int> > q;
    q.push(make_pair(0, st));
    vector<int> dist(100000);
    while(!q.empty()){
        auto front = q.front(); q.pop();
        int lv = front.first;
        int no = front.second;
        for(int i=0; i<numbers.size(); i++){
          int temp = (numbers[i]*no) % mod; 
          if(dist[temp] == 0){
            dist[temp] = lv+1;
            q.push(make_pair(lv+1, temp));
          }
        }
    }
    return dist[target];
}

int main(){
    int n;
    int st;
    int target;
    cin>>n;
    vector<int> number(n, 0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        number[i] = temp;
    }
    cin>>st>>target;
    cout<<minNoOfMul(number, st, target);

    return 0;

}