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

vl group;
ll n,k;

void solve(){
    cin>>n>>k;
    k--;
    ll base; ll idx;
    for(ll i=0; i<group.size(); i++){
        if (group[i] > k) break;
        base = group[i];
        idx=i;
    }
    string ans(n,'a');
    ans[idx+1] = 'b';
    ll left = k-base;
    ans[left] = 'b';

    string temp = "";
    for(char c : ans){
        temp = c+temp;
    }

    cout << temp << endl;
}

int main(){
    ll k=0;
    ll i=0;
    while(k<=2000000000ll){
        k = (i+1)*i; k/=2;
        group.push_back(k);
        i++;
    }

    // for(ll num : group){
    //     cout << num << ' ';
    // }
    // cout << endl;


    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
