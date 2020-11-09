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

ll n,d;
vvl island;

bool comp(vl a, vl b){
    if (a[0] != b[0]) return a[0]<b[0];
    return a[1]<b[1];
}

void solve(){
    island.resize(0);
    for(ll i=0; i<n; i++){
        vl temp = {0,0};
        cin>>temp[0]>>temp[1];
        island.push_back(temp);
    }

    sort(island.begin(), island.end(), comp);

    vector<double> range = {(double)island[0][0]-d-1, (double)island[0][0]-d-1};
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll cur_x = island[i][0], cur_y = island[i][1];
        if (cur_y > d){
            cout << -1 << endl;
            return;
        }
        double dx = pow((d*d - cur_y*cur_y), 0.5);
        vector<double> cur_range = {(double)cur_x - dx, cur_x + dx};
        // cout << "cur_range " << cur_x-dx << ' ' << cur_x+dx << endl;
        if ( cur_range[1] < range[0] || cur_range[0] > range[1]){
            // cout << "non overlap " << cur_x << ' ' << cur_y << endl;
            ans ++;
            range[0] = cur_range[0];
            range[1] = cur_range[1];
            continue;
        }
        range[0] = max(range[0], cur_range[0]);
        range[1] = min(range[1], cur_range[1]);
    }
    cout << ans << endl;
}

int main(){
    ll i=0;
    while(cin>>n>>d){
        if(!n && !d) break;
        cout << "Case " << i+1 << ": ";
        solve();
        i++;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     solve();
    // }

    return 0;
}
