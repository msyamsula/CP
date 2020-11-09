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

ll n;
vl arr;

void solve(){
    cin>>n;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    ll maxnum = -MAXLL;
    ll prev=1;
    ll idx=-MAXLL;
    for(ll i=0; i<n; i++){
        if (arr[i] - prev <=1 ){
            if (arr[i] > prev){
                idx = i;
            }
            maxnum = max(maxnum, arr[i]);
            prev = arr[i];
            continue;
        } else {
            prev = 1;
            continue;
        }
    }

    cout << maxnum << ' ' << idx << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
