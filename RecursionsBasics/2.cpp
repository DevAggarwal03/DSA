#include "../stdc++.h"
using namespace std;

int sumOfNNum(int num){
    if(num == 0){
        return num;
    }
    return num + sumOfNNum(num - 1);

}

int factorialOfN(int num){
    if(num == 1){
        return 1;
    }

    return num*factorialOfN(num - 1);
}

int main(){
    cout<<factorialOfN(5)<<endl;
    return 0;
}