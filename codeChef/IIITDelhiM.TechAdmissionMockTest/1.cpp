#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(){
    int n,q; cin>>n>>q;
    vi arr(n), maxArr(n);
    int m = -(1<<30);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        m = max(arr[i], m);
        maxArr[i] = m;
    }

    for(int i=0; i<q; i++){
        int qry; cin>>qry;
        qry--;
        cout << maxArr[qry] << endl;
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}