#include "../stdc++.h"
using namespace std;

float amtOfWater(int k, int r, int c){
   int i=1;
   int glasses = 0;
   if(r == 1){
    return k>1 ? 1 : k;
   }
   while(i < r){
    int currLevelGlasses = pow(2, i-1);
    glasses += currLevelGlasses;
    i++;
   }
   float waterRem = k - glasses;
   float glassesInRowR = pow(2, r-1);
   float ans = waterRem / glassesInRowR;
   return ans;
}

int main(){
    int k, r, c;
    cin>>k>>r>>c;

    float ans = amtOfWater(k, r, c);
    cout<<endl<<ans;

    return 0;

}