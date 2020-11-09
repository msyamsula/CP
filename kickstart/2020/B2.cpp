#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vl;
typedef vector<vl> vvl;

void solve(int tc){
    long ans = 0;
    long n,d; cin>>n>>d;
    vl bus(n);
    for(long i=0; i<n;i++){
        cin>>bus[i];
        // bus[i] = floor(d/temp)*temp;
        // if (d%long(temp) == 0) bus[i] -= temp;
    }

    for(long i=n-1; i>=0; i--){
        d = floor(double(d)/bus[i])*bus[i];
    }
    ans = d;
    // sort(bus.begin(), bus.end());
    // for(long num : bus){
    //     cout << num << ' ';
    // }
    // cout << endl;
    // vl::iterator it = upper_bound(bus.begin(), bus.end(), d);
    // it--;
    // ans = min(d, *it);

    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0;i<tc; i++){
        solve(i+1);
    }

    return 0;
}