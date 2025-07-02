#include "../stdc++.h"
using namespace std;

class segTree{
    private:
        void buildTree(int ind, int s, int e, vector<int>& nums){
            if(s==e){
                cout<<nums[s]<<" ";
                seg[ind] = nums[s];
                return;
            }

            int mid = (s + e) / 2;
            cout<<mid<<" ";
            buildTree((2*ind)+1, s, mid, nums);
            buildTree((2*ind)+2, mid+1, e, nums);
            seg[ind] = min(seg[(2*ind)+1], seg[(2*ind)+2]);
            return;
        }
    public:
    vector<int> seg;
    segTree(vector<int>& nums){
        seg.resize(nums.size()*4, 0);
        buildTree(0, 0, nums.size()-1, nums);
    }

    int getLength(){
        return seg.size();
    }

    

    int minQuery(int ind, int l, int r, int low, int high){
        if(r < low || l>high){
            return INT_MAX;
        }
        if(l<=low && r>=high){
            return seg[ind];
        }
        int mid = (low + high) / 2;
        int left = minQuery((2*ind) + 1, l, r, low, mid);
        int right = minQuery((2*ind) + 2, l, r, mid+1, high);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
        }

        int mid = (low + high) / 2;
        if(i <= mid){
            update((2*ind) + 1, low, mid, i, val);
        }else{
            update((2*ind) + 2, mid+1, high, i, val);
        }
        seg[ind] = min(seg[(2*ind) + 1], seg[(2*ind) + 2]);
    }
};

int querySeg(int l, int r, segTree* st){
    int high = st->getLength() / 4 - 1;
    return st -> minQuery(0, l, r, 0, high); 
}

void updateSeg(int i, int val, segTree* st){
    int high = st->getLength() / 4 - 1;
    st -> update(0, 0, high, i, val);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        nums[i] = temp;
    }
    segTree* st = new segTree(nums);

    bool breakLoop = false;
    while(!breakLoop){
        cout<<"What do you want to do? \n1 -> query \n2 -> update \n3 -> end \n";
        int n;
        cin>>n;
        switch (n)
        {
        case 1:
            int l;
            cin>>l;
            int r;
            cin>>r;
            cout<<querySeg(l, r, st);
            break;

        case 2:
            int i;
            cin>>i;
            int val;
            cin>>val;
            updateSeg(i, val, st);
            break;

        case 3:
            breakLoop = true;
            break;
        
        default:
            break;
        }

    }

    return 0;

}