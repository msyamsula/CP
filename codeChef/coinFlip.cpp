#include<bits/stdc++.h>
using namespace std;

void solve(){
    int games; cin>>games;
    for(int g=0; g<games; g++){
        // cout << g << endl;
        int i,n,q; cin>>i>>n>>q;
        bool sizeStatus = (n%2 == 0) ? 0 : 1;
        bool findStatus = (i==q) ? sizeStatus : !sizeStatus;
        // cout << g << ' ' << sizeStatus << ' ' << findStatus << endl;
        // cout << i<< ' ' << n << ' ' << q << ' ' << (i==q) << ' ' << sizeStatus << ' ' << not(sizeStatus) << endl;
        if (sizeStatus == 0){
            cout << n/2 << endl;
        } else if (findStatus){
            cout << n/2 << endl;
        } else {
            cout << (n+1)/2 << endl;
        }
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}