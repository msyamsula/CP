#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vl arr;

void solve(){
    ll n; cin>>n;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    sort(arr.begin(), arr.end());
    ll mid1 = floor(double(0+n-1)/2);
    ll mid2 = ceil(double(0+n-1)/2);

    vl can;
    for(ll i=mid1; i<=mid2; i++){
        can.push_back(arr[i]);
    }

    ll ans = 0;
    if(can.size()==1){
        ll pos = can[0];
        for(ll num : arr){
            ans += abs(num-pos);
        }
    } else {
        ll anst = MAXLL;
        for(ll pos=can[0]; pos<=can[1]; pos++){
            ll anstt = 0;
            for(ll num : arr){
                anstt+=abs(num-pos);
            }
            anst = min(anstt, anst);
        }
        ans = anst;
    }

    cout << ans << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ":\n";
        solve();
    }

    return 0;
}
