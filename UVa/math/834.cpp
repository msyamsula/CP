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

ll a,b;
vl ans;

void minimize(ll a, ll b){
    if (b == 1){
        ans.push_back(a);
        return;
    }

    ll bi = floor((double)a/b);
    ans.push_back(bi);
    return minimize(b, a-(b*bi));
}

void solve(){
    ans.resize(0);
    minimize(a,b);
    cout << '[';
    for(ll i=0; i<ans.size(); i++){
        if (i!=0){
            if (i==1) cout << ';';
            else cout << ',';
        }
        cout << ans[i];
    }
    cout << ']' << endl;
}

int main(){
    while(cin>>a>>b){
        solve();
    }

    return 0;
}
