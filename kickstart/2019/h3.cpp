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
ll N=9, max_num = 900;
vvl dp;

ll get_number(ll idx){
    return idx-max_num;
}

ll get_idx(ll number){
    return number+max_num;
}

void solve(){
    ll length = 0;
    for(ll i=0; i<N; i++){
        cin>>arr[i];
        length += arr[i];
    }
    dp.assign(length+1, vl(2*max_num+1, 0));
    dp[0][0] = 1;
    vl used; used.assign(9, 0);
    for(ll i=0; i<length; i++){
        for(ll j=0; j<=get_idx(max_num); j++){
            if (dp[i][j] == 0) continue;
            ll cur_status = get_number(j);
            for(ll ii=0; ii<N; ii++){
                if (used[ii] == arr[ii]) continue;
                ll next_status = cur_status;
            }
        }
    }
}

int main(){
    arr.assign(N, 0);
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
