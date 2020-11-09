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

ll findMin(ll aa, ll bb, ll xx, ll yy,ll nn){
    ll db = bb-yy;
    bb -= min(db,nn);
    nn -= min(db,nn);

    if (nn==0) return aa*bb;

    ll da = aa-xx;
    aa -= min(da,nn);

    return aa*bb;
}

ll a,b,x,y,n;

void solve(){
    cin>>a>>b>>x>>y>>n;
    ll d = a+b-x-y-n;
    if (d<=0){
        cout << (x*y) << endl;
        return;
    }

    cout << min(findMin(a,b,x,y,n), findMin(b,a,y,x,n)) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
