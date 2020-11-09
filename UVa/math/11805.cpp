#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,p;
    cin>>n>>k>>p;
    int offset = k-1;
    int end = p%n;
    end = (end+offset)%n;

    cout << end+1 << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case " << i+1 << ": ";
        solve();
    }

    return 0;
}