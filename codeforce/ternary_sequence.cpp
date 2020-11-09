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

ll xa,ya,za;
ll xb,yb,zb;

void solve(){
    cin>>xa>>ya>>za;
    cin>>xb>>yb>>zb;

    ll ans = 0;
    // pair 2a with 1b
    ll m = min(za,yb);
    za -= m;
    yb -= m;

    // calculate positif value
    ans += 2*m;

    // if 2a is still there, pair it with 2b
    if (za > 0){
        m = min(za, zb);
        za-=m;
        zb-=m;
    }

    // if still there pair it with 0b
    if (za > 0){
        m = min(za, xb);
        za -= m;
        xb -= m;
    }

    // pair 1a with 0b
    m = min(ya, xb);
    ya -= m;
    xb -= m;

    // if still there pair it with 1b
    if (ya > 0){
        m = min(ya, yb);
        ya -= m;
        yb -= m;
    }

    // if still there pair it with 2b
    if (ya > 0){
        m = min(ya, zb);
        ya -= m;
        zb -= m;
        // calculate negative value
        ans -= 2*m;
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
