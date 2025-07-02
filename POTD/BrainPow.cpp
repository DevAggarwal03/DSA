#include "../stdc++.h"

using namespace std;


long long bp(vector<vector<int> >& questions){
    vector<long long> ansArr(questions.size(), 0);
        
    for(int i=questions.size() - 1; i>=0; i--){
        int index = i + questions[i][1] + 1;
        if(index < questions.size()){
            long long temp = questions[i][0] + ansArr[index];
            ansArr[i] = temp;
        }else{
            ansArr[i] = questions[i][0];
        }
        if(i < questions.size() - 1){
            ansArr[i] = max(ansArr[i+1], ansArr[i]);
        }
    }

    return ansArr[0];
}

