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

ll m,s;

void solve(){
    cin>>m>>s;
    ll min_sum = 1;
    ll max_sum = 9*m;

    if (s<min_sum || s>max_sum){
        cout << "-1 -1" << endl;
        return;
    }

    vl small;
    ll digit = s/m;
    ll mod = s%m;
    for(ll i=0; i<m; i++){
        small.push_back(digit);
    }
    for(ll i=m-1; i>=0; i--){
        if (mod==0) break;
        small[i]++;
        mod--;
    }

    vl big;
    mod = s%m;
    for(ll i=0; i<m; i++){
        big.push_back(digit);
    }
    for(ll i=0; i<m; i++){
        if (mod==0) break;
        big[i]++;
        mod--;
    }

    // for(ll num : big){
    //     cout << num;
    // }
    // cout << endl;

    ll start = 0, end = m-1;
    while (big[start] == 9 && start<end) start++;
    while (big[end] == 0 && start<end) end--;
    while (start!=end){
        // cout << start << ' ' << end << endl;
        ll ask = 9-big[start];
        ll give = big[end];
        ll transfer = min(ask, give);
        big[start]+=transfer;
        big[end]-=transfer;
        if (big[start] == 9) start++;
        if (big[end] == 0) end--;
        if (start == end || end<start) break;
    }

    
    // if (end<start){
    //     cout << "-1" << endl;
    // } else {
    // }

    start = 0; end = m-1;
    while (small[start] == 1 && start<end) start++;
    while (small[end] == 9 && start<end) end--;
    // cout << start << ' ' << end << endl;
    while (start!=end && start<end){
        ll ask = 9-small[end];
        ll give = small[start]-1;
        ll transfer = min(ask, give);
        small[end]+=transfer;
        small[start]-=transfer;
        if (small[start] == 1) start++;
        if (small[end] == 9) end--;
        if (start == end || end<start) break;
        // cout << start << ' ' << end << ' ';
        // cout << "small: ";
        // for(ll num : small){
        //     cout << num;
        // }
        // cout << endl;
    }

    // cout << "small: ";
    for(ll num : small){
        cout << num;
    }
    cout << ' ';

    // cout << "big: ";
    for(ll num : big){
        cout << num;
    }
    cout << endl;
    // if (end<start){
    //     cout << "-1" << endl;
    // } else {
    // }

}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
