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

string s;

void solve(){
    cin>>s;
    ll n= s.size();
    ll ones,zeros;
    ones=zeros=0;
    vl ps = {0};
    for(char c : s){
        if (c == '1') ones++;
        else zeros++;

        ll num = c-'0';
        ll sum = *ps.rbegin() + num;
        ps.push_back(sum);
    }

    ll ans = min(ones,zeros);

    for(ll i=0; i<n; i++){
        ll left_sum = ps[i+1]-ps[0];
        ll right_sum = ps[n]-ps[i+1];

        ll left_one_cost = (i+1) - left_sum + (right_sum);
        ll left_zero_cost = left_sum + (n-(i+1)-right_sum);

        ll min_cost = min(left_one_cost, left_zero_cost);
        ans = min(ans, min_cost);
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
