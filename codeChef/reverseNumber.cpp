#include<bits/stdc++.h>
using namespace std;

void solve(){
    string n; cin>>n;
    string ans = "";
    for(int i=n.size()-1; i>=0; i--){
        ans += n[i];
    }
    cout << stoi(ans) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}