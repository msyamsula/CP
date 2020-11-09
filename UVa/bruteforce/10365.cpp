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

vl cur_configuration;
ll N, min_area, w, sum, box_left;

void search(ll target){
    // cout << target << ' ' << box_left << endl;
    ll n = cur_configuration.size();
    // for(ll num : cur_configuration){
    //     cout << num << ' ';
    // }
    // cout << n << ' ' << w << ' ' << (n==w || target == 0);

    // cout << endl;
    

    if ( n == w || sum == N){
        if (sum != N) return;
        ll area = 0;
        for(ll i=0; i<n; i++){
            // cout << cur_configuration[i] << ' ';
            area += 2+cur_configuration[i]*4;
            if (i!=0) area -= 2*min(cur_configuration[i-1], cur_configuration[i]);
        }
        // cout << endl;

        min_area = min(area, min_area);
        return;
    }


    for(ll i=target; i>0; i--){
        if (i>box_left) continue;
        cur_configuration.push_back(i);
        box_left -= i;
        sum += i;
        search(i);
        sum -= i;
        box_left += i;
        cur_configuration.pop_back();
    }
}

void solve(){
    cin>>N;
    for(ll i=0; i<=N; i++){
        if(i*i >= N){
            w=i; break;
        }
    }

    vl conf;
    vl range_update; range_update.assign(w+1, 0);
    while(N>0){
        if (N>=w){
            range_update[0]++;
            range_update[w]--;
            N-=w;
        } else {
            range_update[0]++;
            range_update[N]--;
            N-=N;
        }
    }

    ll sum = 0;
    for(ll i=0; i<w; i++){
        sum+=range_update[i];
        conf.push_back(sum);
    }


    for(ll num : conf){
        cout << num << ' ';
    }
    cout << endl;
    conf = {10,10,10, 10, 10,10,10,10,10,10};
    ll ans = 0;
    for(ll i=0; i<w; i++){
        ans += 2 + conf[i]*4;
        if (i!=0) ans -= 2*min(conf[i-1], conf[i]);
    }

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
