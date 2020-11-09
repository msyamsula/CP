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

string a;

void solve(){
    cin>>a;
    vl arr;
    for(char c : a){
        ll num = c-'0';
        if (c=='+') continue;
        else arr.push_back(num);
    }

    sort(arr.begin(), arr.end());
    for(ll i=0; i<arr.size(); i++){
        if (i!=0) cout << '+';
        cout << arr[i];
    }
    cout << endl;
}

int main(){
    // int tc; cin>>tc;
    ll tc=1;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
