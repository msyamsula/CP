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

ll n,a,b;
vvl graphup, graphdown;
vl paint;
ll tot;

void bfs(ll a, ll mod){
    queue<ll> q; q.push(a);
    vl d(n);
    d[a]=0;
    if(!paint[a]){
        paint[a]=1;
        tot++;
    }
    // ll ans = 1;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        // cout << u << endl;
        for(ll v : graphup[u]){
            q.push(v);
            d[v] = d[u]+1;
            if (d[v] % mod == 0 && paint[v] == 0){
                paint[v]=1;
                tot++;
                // ans++;
            }
        }
    }

    // return ans;
}

void solve(){
    cin>>n>>a>>b;
    graphup.resize(0); graphup.resize(n);
    graphdown.resize(0); graphdown.resize(n);
    for(ll i=0; i<n-1; i++){
        ll u = i+1, p;
        cin>>p; p--;
        graphdown[p].push_back(u);
        graphup[u].push_back(p);
    }

    // cout << "graph: " << endl;
    // for(vl arr: graphup){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout<< "end" << endl;

    ll cnt=0;
    paint.resize(0); paint.resize(n);
    // bfs(5,3);
    // bfs(6,2);
    // for(ll num: paint){
    //     cout << num << ' ';
    // }
    // cout << endl;
    ll sumtot = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            paint.resize(0); paint.assign(n,0);
            tot = 0;
            bfs(i,a); bfs(j,b);
            sumtot+=tot;
            // cout << "tot: " << tot << endl;
        }
    }

    cout << fixed << setprecision(7) << (double)sumtot/(n*n) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
