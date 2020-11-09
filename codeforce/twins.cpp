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

ll n;
vl arr;

void solve(){
    arr.resize(0);
    cin>>n;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    vl ps_arr = {0};
    for(ll i=0; i<n; i++){
        ll temp = arr[i] + *ps_arr.rbegin();
        ps_arr.push_back(temp);
    }

    ll cnt = 0;
    for(ll i=n-1; i>=0; i--){
        ll rps = ps_arr[n]-ps_arr[i];
        ll lps = ps_arr[i] - ps_arr[0];
        if (rps > lps){
            cnt = n-i;
            break;
        }
    }

    cout << cnt << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
