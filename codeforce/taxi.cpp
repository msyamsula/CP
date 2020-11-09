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
map<ll, ll> mem;

void solve(){
    cin>>n;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
        mem[temp]++;
    }

    sort(arr.begin(), arr.end());

    // iterate in mem
    // for(auto it=mem.begin(); it!=mem.end(); it++){}
    auto it = mem.begin();
    while(it != mem.end()){
        ll group = it->first;
        ll cnt = it->second;
        ll inlcude = cnt;
        // find self group
        // if self group size == 1 pass
        
        for(ll i=group; i<=4; i++){
            // look for other group
            mem.find(i)
        }
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
