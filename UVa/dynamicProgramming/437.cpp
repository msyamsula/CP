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

ll n,tc;
vvl blocks; //l,w,h,area, l<w

bool comp(vl a, vl b){
    return a[3]>b[3];
}

void solve(){
    set<vl> bl;
    blocks.resize(0);
    for(ll i=0; i<n; i++){
        ll a,b,c; cin>>a>>b>>c;
        vl arr = {a,b,c};
        sort(arr.begin(), arr.end());
        a=arr[0];
        b=arr[1];
        c=arr[2];
        if (bl.find({a,b,c}) == bl.end()){
            blocks.push_back({a,b,c,a*b});
            bl.insert({a,b,c});
        }
        if (bl.find({a,c,b}) == bl.end()){
            blocks.push_back({a,c,b,a*c});
            bl.insert({a,c,b});
        }
        if (bl.find({b,c,a}) == bl.end()){
            blocks.push_back({b,c,a,b*c});
            bl.insert({b,c,a});
        }
    }

    sort(blocks.begin(), blocks.end(), comp);

    // cout << "blocks: " << endl;
    // for(vl ar : blocks){
    //     for(ll num : ar){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    n = blocks.size();
    vl dp; dp.resize(n);
    for(ll i=0; i<n; i++){
        dp[i] = blocks[i][2];
    }
    // for(ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << n << endl;

    ll ans = 0;
    for(ll i=1; i<n; i++){
        // dp[i] = blocks[i][2];
        for(ll j=0; j<i; j++){
            if (blocks[j][0] > blocks[i][0] && blocks[j][1] > blocks[i][1]){
                dp[i] = max(dp[i], dp[j]+blocks[i][2]);
            }
        }
        ans = max(ans, dp[i]);
    }

    // for(ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << endl;
    cout << "maximum height = " << ans << endl;
}

int main(){
    tc = 1;
    while(cin>>n){
        if (!n) break;
        cout << "Case " << tc << ": ";
        solve();
        tc++;
    }

    return 0;
}
