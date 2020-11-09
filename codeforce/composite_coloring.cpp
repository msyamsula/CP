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

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    arr.resize(0);
    cin>>n;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    vvl mem;
    vl color(n,0);
    set<ll> c;
    // mem.resize(n);
    for(ll i=0; i<n; i++){
        ll clr;
        cout << "i: " << arr[i] << endl;
        if (color[i]!=0){
            clr = color[i];
            continue;
        } else {
            clr = c.size()+1;
            c.insert(clr);
            color[i] = clr;
        }
        if (i==n) continue;
        for(ll j=i+1; j<n; j++){
            if (color[j] != 0) continue;
            ll a = arr[i], b = arr[j];
            if (gcd(a,b) != 1){
                // mem[i].push_back(j);
                color[j] = clr;
                // cout << "not co-prime " << a << ' ' << b << endl;
            } else {
            }
        }
    }

    // ll clr = c.size()+1;
    // c.insert(clr);
    // if (color[n-1] == 0) color[n-1] = clr;

    // // cout << mem.size() << endl;
    // for(ll i=0; i<n; i++){
    //     ll clr;
    //     if (color[i] != 0){
    //         clr = color[i];
    //     } else {
    //         clr = c.size()+1;
    //         color[i] = clr;
    //         c.insert(clr);
    //     }
    //     for(ll j=0; j<mem[i].size(); j++){
    //         // cout << mem[i][j] << ' ';
    //         if (color[mem[i][j]] != 0) continue;
    //         c.insert(clr);
    //         color[mem[i][j]] = clr;
    //     }
    //     // cout << endl;
    // }

    cout << c.size() << endl;
    for(ll i=0; i<n; i++){
        if (i!=0) cout << ' ';
        cout << color[i];
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
