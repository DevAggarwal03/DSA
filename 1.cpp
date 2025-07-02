#include <iostream>

using namespace std;

void pattern1(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern2(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern3(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<=i; j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void pattern4(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<=i; j++){
            cout<< i+1<<" ";
        }
        cout<<endl;
    }
}

void pattern5(int num){
    for(int i=0; i<num; i++){
        for(int j=num - i; j > 0; j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern6(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<num-i; j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void pattern7(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<= (2*(num - i) - 1)/2; j++){
            cout<<" ";
        }
        for(int j=0; j< 2*i + 1; j++){
            cout<<"*";
        }
        for(int j=0; j<= (2*(num - i) - 1)/2; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern8(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<i;j++){
            cout<<" ";
        }
        for(int j=0; j<(2*(num - i) - 1); j++){
            cout<<"*";
        }
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern9(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<(2*(num - i) - 1)/2; j++){
            cout<<" ";
        }
        for(int j=0; j<(2*i + 1); j++){
            cout<<"*";
        }
        for(int j=0; j<(2*(num - i) - 1)/2; j++){
            cout<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<num; i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int j=0; j<(2*(num - i) - 1); j++){
            cout<<"*";
        }
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern10(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=0; i<num - 1; i++){
        for(int j=num - i - 1; j>1; j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern11(int num){
    int toggle = 1;
    for(int i=0; i<num; i++){
        if(i > 0 ){
            if(i % 2 != 0){
                toggle = 0;
            }else{
                toggle = 1;
            }
        }
        for(int j=0; j<=i; j++){
            cout<<toggle<<" ";
            toggle = 1 - toggle;
        }
        cout<<endl;
    }
}

void pattern12(int num){
    int initialSpace = 2*num - 2;
    for(int i=0; i<num; i++){
        for(int j=0; j<=i; j++){
            cout<<j+1;
        }
        for(int j=0; j<(initialSpace - (2*i)); j++){
            cout<<" ";
        }
        for(int j=i+1; j>=1; j--){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern13(int num){
    int start = 1;
    for(int i=0; i<num; i++){
        for(int j=0; j<=i; j++){
            cout<<start<<" ";
            start++;
        }
        cout<<endl;
    }
}

void pattern14(int num){
    char start = 'A';
    for(int i=0; i<num; i++){
        for(int j=0; j<=i; j++){
            cout<<char(start + j);
        }
        cout<<endl;
    }
}

void pattern15(int num){
    char start = 'A';
    for(int i=0; i<num; i++){
        for(int j = 0; j<(num - i); j++){
            cout<<char(start + j);
        }
        cout<<endl;
    }
}

void pattern16(int num){
    char start = 'A';
    for(int i=0; i<num; i++){
        for(int j=0; j<=i; j++){
            cout<<char(start);
        }
        start = start + 1;
        cout<<endl;
    }
}

void pattern17(int num){
    char start = 'A';
    for(int i=0; i<num; i++){
        for(int j=0; j<(2*(num - i) - 1)/2; j++){
            cout<<" ";
        }
        if(i > 0){
            for(int j=0; j<=i; j++){
                cout<<char(start+j);
            }
            for(int j=i; j>0; j--){
                cout<<char(start + j - 1);
            }
        }else{
            cout<<char(start);
        }
        for(int j=0; j<(2*(num - i) - 1)/2; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern18(int num){
    for(int i=0; i<num; i++){
        for(int j=0; j<num-i; j++){
            cout<<"* ";
        }
        for(int j=0; j<2*i; j++){
            cout<<" ";
        }
        for(int j=0; j<2*i; j++){
            cout<<" ";
        }
        for(int j=0; j<num-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=0; i<num; i++){
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        for(int j=0; j<2*(num-1-i); j++){
            cout<<" ";
        }
        for(int j=0; j<2*(num-1-i); j++){
            cout<<" ";
        }
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern21(int num){
    for(int i=0; i<num; i++){
        if(i==0 || i==num - 1){
            for(int j=0; j<num; j++){
                cout<<"* ";
            }
        }else{
            cout<<"* ";
            for(int j=0; j<num - 2; j++){
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern22(int num){
    for(int i=0; i<2*num - 1; i++){
        for(int j=0; j<2*num - 1; j++){
            int top = i;
            int left = j;
            int right = (2*num - 2) - j;
            int bottom = (2*num - 2) - i;
            int minimumDis = min(min(top, left), min(right, bottom));
            cout<< num-minimumDis;
        }
        cout<<endl;
    }
}

int main(){
   int noOfInputs;
   cin>>noOfInputs;
   int inputs[noOfInputs];
   for(int i=0; i<noOfInputs; i++){
    cin>>inputs[i];
   }

   for(int i=0; i<noOfInputs; i++){
    pattern22(inputs[i]);
    cout<<endl;
   }
}
