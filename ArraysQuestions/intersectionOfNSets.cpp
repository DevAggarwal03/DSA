#include "../stdc++.h"
using namespace std;

int binarySearchFreq(vector<int> arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int mid = (s + e) / 2;
    int cnt = 0;
    while(s < e){
        if(arr[mid] == target){
            e = mid;
        }
        else if(arr[mid] > target){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = (s + e)/2;
    }
    if(arr[mid] != target){
        return 0;
    }
    
    
    while(arr[mid] == target){
        cnt++;
        mid++;
    }
    
    return cnt;
}

vector<int> getIntersection(vector<vector<int> > sets){
    int rows = sets.size();
    for(int i=0; i<rows; i++){
        sort(sets[i].begin(), sets[i].end());
    }
    int minSize = INT_MAX;
    int minSet = -1;
    for(int i=0; i<rows; i++){
        if(sets[i].size() < minSize){
            minSet = i;
            minSize = sets[i].size();
        }
    }

    unordered_map<int, int> mp;
    for(int i=0; i<sets[minSet].size(); i++){
        mp[sets[minSet][i]]+=1;
    }

    for (auto it : mp){
        int freq = INT_MAX;
        for(int i=0; i<sets.size(); i++){
            int res = binarySearchFreq(sets[i], it.first);
            if(res == 0){
                freq = res;
                break;
            }
            if(res < freq){
                freq = res;
            }
        }
        mp[it.first] = freq;
        
    }

    
    vector<int> ans;
    for (auto it : mp){
        if(it.second == 0){
            cout<<it.first<<endl;
            continue;
        }
        for(int i=0; i<it.second; i++){
            ans.push_back(it.first);
        }
    }

    return ans;

}

void printset(vector<int> arr){
    cout<<"printing"<<endl;
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

void TestCase1()
{
    vector < vector <int> > sets;
    vector <int> set1;
    set1.push_back(1);
    set1.push_back(1);
    set1.push_back(2);
    set1.push_back(2);
    set1.push_back(5);
    set1.push_back(5);

    

    vector <int> set2;
    set2.push_back(1);
    set2.push_back(1);
    set2.push_back(4);
    set2.push_back(3);
    set2.push_back(5);
    set2.push_back(9);
    set2.push_back(5);

    sets.push_back(set2);
    sets.push_back(set1);

    vector <int> set3;
    set3.push_back(1);
    set3.push_back(1);
    set3.push_back(2);
    set3.push_back(3);
    set3.push_back(5);
    set3.push_back(6);
    set3.push_back(5);

    sets.push_back(set3);
    vector <int> r = getIntersection(sets);

    printset(r);

}

int main(){
    TestCase1();
    return 0;
}