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

// O(N)
void solve(){
    cin>>n;
    // vl ps; ps.assign(n+1, 0);
    ll ones = 0;
    ll ps = 0;
    ll max_num = -MAXLL;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        ll val = (temp == 1) ? -1 : 1;
        if (temp == 1) ones++;
        ll copy = ps+val;
        max_num = max(copy, max_num);
        copy = max(0ll, copy);
        ps = copy;
        // cout << "temp: " << temp << endl;
        // cout << "val: " << val << endl;
        // cout << "ps: " << ps << endl;
        // ps[i+1] = ps[i] + val;
        // ps[i+1] = max(0ll, ps[i+1]);
    }


    // for(ll i=0; i<n+1; i++){
    //     max_num = max(max_num, ps[i]);
    // }

    cout << ones+max_num << endl;
}

// void solve(){
//     cin>>n;
//     arr.resize(0);
//     vl pso(1,0);
//     vl psz(1,0);
//     for(ll i=0; i<n; i++){
//         ll temp; cin>>temp;
//         arr.push_back(temp);
//         ll one = (temp == 1) ? 1 : 0;
//         ll zero = (temp == 0) ? 1 : 0;
//         ll npso = *pso.rbegin()+one;
//         pso.push_back(npso);
//         ll npsz = *psz.rbegin()+zero;
//         psz.push_back(npsz);
//     }

//     ll ans = 0;

//     for(ll i=0; i<n; i++){
//         for(ll j=i; j<n; j++){
//             ll left_one = pso[i]-pso[0];
//             ll zero_mid = psz[j+1] - psz[i];
//             ll right_one = pso[n] - pso[j+1];

//             ll cnt = left_one + zero_mid + right_one;

//             ans = max(ans, cnt);
//         }
//     }

//     cout << ans << endl;
// }

int main(){
    solve();

    return 0;
}
