#include<bits/stdc++.h>
using namespace std;

long bs(long left, long right, long w){
    if (left == right) return right;
    long mid = (left+right)/2;
    long eval = mid*(mid+1)/2;
    // cout << mid << endl;
    if (eval == w) return mid;

    if(eval<w){
        return bs(mid+1, right, w);
    } else {
        return bs(left, mid, w);
    }

}

void solve(int tc){
    long w; cin>>w;
    long upperlimit = pow(2*w, 0.5)+1;
    long row = bs(0,upperlimit,w);

    long e = row*(row+1)/2;
    if (e > w){
        cout << row-1 << endl;
        return;
    }

    cout << row << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}