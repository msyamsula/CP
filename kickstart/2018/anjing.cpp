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

ll N, K;
vl arr;

void solve(){
    cin>>N>>K;
    arr.resize(0);
    for(ll i=0; i<N; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    ll same_day = 0;
    ll day = 0;
    ll total = 0;
    for(ll i=0; i<N; i++){
        if (day < arr[i]){
            same_day++;
            total++;
            if (same_day==K){
                day++;
                same_day = 0;
            }
        }
    }

    cout << total << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
