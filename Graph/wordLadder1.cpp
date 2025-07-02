#include "../stdc++.h"
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    
    queue<pair<string,int> > q;
    wordSet.erase(beginWord);
    q.push(make_pair(beginWord, 1)); 
    while(!q.empty()){
        auto front = q.front(); q.pop();
        string word = front.first;
        int lv = front.second;
        for(int i=0; i<word.length(); i++){
            char original = word[i];
            for(int j=0; j<26; j++){
                char newChar = char('a' + j);
                word[i] = newChar;
                
                if(wordSet.find(word) != wordSet.end()){
                    if(word == endWord){
                        return lv+1;
                    }
                    q.push(make_pair(word, lv+1));
                    wordSet.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return -1;
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

    cout<<ladderLength(beginWord, endWord, wordList);

    return 0;

}
