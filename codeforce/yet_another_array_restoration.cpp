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
void showV(vl temp){
    for(ll t : temp){
        cout << t << ' ';
    }
    cout << endl;
}

void showVV(vvl temp){
    for (vl t : temp){
        for(ll t1 : t){
            cout << t1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

ll n,x,y;

void solve(){
    cin>>n>>x>>y;
    // cout << "x, y: " << x << ' ' << y << endl;
    ll dmin, astart, maxnum=MAXLL;
    for(ll i=0; i<n-1; i++){
        for(ll j=i+1; j<n; j++){
            double d = double(y-x)/(j-i);


            if (d == floor(d)){
                ll start = x-i*d;
                ll end = start+(n-1)*d;
                if (end < maxnum && start > 0){
                    dmin = d;
                    astart = start;
                    maxnum = end;
                }
                // if (i==0 && j==n-1){
                //     cout << "investigation: " << d << ' ' << start << ' ' << end << ' ' << maxnum << endl;
                // }
            }
        }
    }

    for(ll i=0; i<n; i++){
        if (i!=0) cout << ' ';
        cout << astart + i*dmin;
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
