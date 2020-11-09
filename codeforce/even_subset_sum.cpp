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
vl arr, ans, used;
vvl dp;

void backtrack(ll r, ll c){
    // cout << "at: " << r << ' ' << c << endl;
    if (c==0 && r==0) return;

    for(ll i=0; i<n; i++){
        ll nj = c - arr[i];
        if (nj<0 || used[i] == 1) continue;
        if (dp[r-1][nj] == 1){
            ans.push_back(i);
            used[i] = 1;
            return backtrack(r-1,nj);
        }
    }
}

void solve(){
    cin>>n;
    arr.resize(0);
    ll maxsum = 0;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
        maxsum+=temp;
    }

    dp.resize(0); dp.assign(1, vl(maxsum+1, 0));
    dp[0][0] = 1;
    bool found = 0;
    ll ii=0;
    ll jstart,istart;
    while(!found){
        vl copy(maxsum+1, 0);
        for(ll j=0; j<maxsum+1; j++){
            if (dp[ii][j] == 0) continue;
            ll num = arr[ii];
            ll nj = j+num;
            if (nj>maxsum) continue;
            copy[nj] = 1;
            copy[j] = 1;
            if (nj%2 == 0 && !found){
                found = 1;
                jstart = nj;
                istart = ii+1;
            }
        }

        dp.push_back(copy);
        ii++;
        if (ii == n) break;
    }
    // cout << "dp: " << endl;
    // for(vl arr : dp){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    if (!found){
        cout << -1 << endl;
        return;
    }


    ans.resize(0);
    used.resize(0); used.assign(n,0);
    backtrack(istart, jstart);

    cout << ans.size() << endl;

    // cout << "ans: ";
    sort(ans.begin(), ans.end());
    for(ll i=0; i<ans.size(); i++){
        ll num = ans[i];
        if (i!=0) cout << ' ';
        cout << num+1;
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
