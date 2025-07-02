#include "../stdc++.h"
using namespace std;

vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<vector<string> > q;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<string> temp;
    temp.push_back(beginWord);
    q.push(temp);
    wordSet.erase(beginWord);
    vector<vector<string> > ans;
    while(!q.empty()){
        int size = q.size();
        vector<string> toBeErasedLast;
        for(int i=0; i<size; i++){
            vector<string> front = q.front(); q.pop();
            string lastWord = front.back();
            if(lastWord == endWord){
                ans.push_back(front);
                continue;
            }
            for(int j=0; j<lastWord.size(); j++){
                char original = lastWord[j];
                for(int k=0; k<26; k++){
                    char newChar = char('a' + k);
                    lastWord[j] = newChar;
                    if(wordSet.find(lastWord) != wordSet.end()){
                        front.push_back(lastWord);
                        q.push(front);
                        toBeErasedLast.push_back(lastWord);
                        front.pop_back();
                    }
                }
                lastWord[j] = original;
            }
        }
        for(auto it: toBeErasedLast){
            wordSet.erase(it);
        }
    }
    return ans;
}

int main(){

    string beginWord, endWord;
    vector<string> wordList;
    int n;
    cin>>beginWord>>endWord;
    cin>>n;
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        wordList.push_back(temp);
    }

    vector<vector<string> > ans = findLadders(beginWord, endWord, wordList);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;

}