#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    // vi speed(n);
    int ans = 1;
    int limit; cin>>limit;
    int speed;
    for(int i=1; i<n; i++){
        cin>>speed;
        if (speed<=limit){
            limit = speed;
            ans++;
        }
    }

    cout << ans << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}