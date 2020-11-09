#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vi;

long xortil(long x){
    // cout << "xortil " << x << endl;
    if (x==0) return 0;
    if (x==1) return 1;
    if (x==2) return 3;

    long remainder = (x-3)%4;
    // cout << remainder << endl;
    long ans=0;
    for(long i=x-remainder+1; i<=x; i++){
        // cout << i << endl;
        ans ^= i;
    }

    // cout << "ans" << endl;
    // cout << ans << endl;
    return ans;
}

void solve(){
    long l,r; cin>>l>>r;
    long a = xortil(l-1), b = xortil(r);
    long ans = b^a;
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
        // bitset<64> num = 100;
        // cout << num << endl;
        // cout << num[4] << endl;
        // cout << num[6] << endl;
    }

    return 0;
}