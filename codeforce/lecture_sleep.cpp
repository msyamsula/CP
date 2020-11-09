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

ll n,k;
vl theorems;

void solve(){
    cin>>n>>k;
    theorems.resize(0);
    vl pst={0};
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        theorems.push_back(temp);
        ll sum = temp+(*pst.rbegin());
        pst.push_back(sum);
    }
    vl misha;
    vl psm={0};
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        misha.push_back(theorems[i]*temp);
        ll sum = *misha.rbegin() + *psm.rbegin();
        psm.push_back(sum);
    }

    ll c_score = psm[n]-psm[0];
    ll max_gain = -MAXLL;
    for(ll i=0; i<=n-k; i++){
        ll remove = psm[i+k]-psm[i];
        ll add = pst[i+k]-pst[i];
        max_gain = max(max_gain, add-remove);
    }

    cout << c_score + max_gain << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     // cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
