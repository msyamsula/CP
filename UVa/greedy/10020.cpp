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

ll m;
// vvl arr;
vl ufd;

ll parent(ll a){
    if (ufd[a] < 0) return a;
    return parent(ufd[a]);
}

void join_range(ll a, ll b){
    for(ll i=max(a,0ll); i<=min(m,b); i++){
        if (parent(i) == m+1) break;
        ufd[i]=m+1;
        ufd[m+1]--;
    }

    for(ll i=min(b,m); i>=max(0ll,a); i--){
        if (parent(i) == m+1) break;
        ufd[i]=m+1;
        ufd[m+1]--;
    }
}

bool comp(vl a, vl b){
    // if (a[3] != b[3]) return a[3]<b[3];
    if (a[0] != b[0]) return a[0]<b[0];
    if (a[2] != b[2]) return a[2]>b[2];

    return a[1]>b[1];
}


vvl ans;

void backtrack(ll idx, vvl interval){
    if (idx==0) return;
    for(ll i=0; i<interval.size(); i++){
        ll a=interval[i][0],b=interval[i][1];
        if (b>=idx){
            ans.push_back({a,b});
            return backtrack(max(a,0ll), interval);
        }
    }
}

void solve(){
    cin>>m;
    // cout << m << endl;
    ufd.resize(0); ufd.assign(m+2, -1);
    ufd[m+1] = 0;
    vvl interval;
    // vl start, end;
    ll a,b;
    // cout << "interval: " << endl;
    unordered_map<ll, ll> interval_set;
    while(cin>>a>>b){
        if(!a && !b) break;
        // ll range = min(b,m) - max(0ll,a);
        if (b<0 || a>m) continue;
        ll real_a = max(0ll, a), real_b = min(b,m);
        // ll real_a = a, real_b=b;
        // if (interval_set.find({real_a,real_b}) != interval_set.end()) continue;
        // interval_set[{real_a,real_b}] =1;
        if (interval_set.find(real_a) != interval_set.end() && interval_set.at(real_a)==real_b) continue;
        interval_set[real_a] = real_b;
        // cout << a << ' ' << b << endl;
        ll range = min(m,b) - max(0ll, a) + 1;
        interval.push_back({a,b,range});
        // start.push_back(a); end.push_back(b);
        // cout << a << ' ' << b << endl;
    }

    sort(interval.begin(), interval.end(), comp);
    if ( interval.size()==0 || interval[0][0] > 0){
        cout << 0 << endl;
        return;
    }

    // cout << "interval" << endl;
    // for(vl a : interval){
    //     for(ll num : a){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    vl dp; dp.assign(m+1, MAXLL);
    // dp[0] = 1;
    ll start = max(0ll, interval[0][0]);
    start = min(start,m);
    dp[start]= 0;
    for(ll i=start; i<m; i++){
        for(ll j=0; j<interval.size(); j++){
            ll a=max(0ll, interval[j][0]), b=min(interval[j][1],m);
            if (a>i) break;
            if (b<=i) continue;
            dp[b] = min(dp[b], dp[i]+1);
        }
    }

    // cout << "dp: ";
    // for(ll i=0; i<dp.size(); i++){
    //     if (i!=0) cout << ' ';
    //     cout << dp[i];
    // }
    // cout << endl;

    if (dp[m] == MAXLL){
        cout << 0 << endl;
        return;
    }

    // cout << "tes" << endl;

    ans.resize(0);
    backtrack((ll)m, interval);
    sort(ans.begin(),ans.end());

    cout << dp[m] << endl;
    // cout << "ans: " << endl;
    for(vl a:ans){
        for(ll i=0; i<a.size(); i++){
            if (i!=0) cout << ' ';
            cout << a[i];
        }
        cout << endl;
    }

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if (i!=0) cout << endl;
        // cout << i << endl;
        solve();
    }

    return 0;
}
