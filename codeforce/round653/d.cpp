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

void solve(){
    cin>>n>>k;
    map<ll, ll> target;
    // target.clear();
    // ll total = 0;
    // ll sz = 200000;
    // vl target; target.assign(sz+1,0);
    ll x=0, step=0;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        ll t = k-(temp%k);
        if (t!=k){
            target[t]++;
            step = max(step, t+(target[t]-1)*k);
            // total++;
        }
    }

    // for(pair<ll, ll> p : target){

    // }

    // cout << "target: ";
    // for(ll num : target){
    //     cout << num << ' ';
    // }
    // cout << endl;
    if(target.size() == 0){
        cout << 0 << endl;
        return;
    }

    // for(pair<ll, ll> p : target){
    //     step = max(step, p.first+(p.second-1)*k);
    // }
    // for(ll i=1; i<min(k,n); i++){
    //     if (target.find(i) == target.end()) continue;
    //     step = max(step, i+(target.at(i)-1)*k);
    // }
    // ll i =0;
    

    cout << step+1 << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}


// #include <bits/stdc++.h>

// using namespace std;

// int main() {
// #ifdef _DEBUG
// 	freopen("input.txt", "r", stdin);
// //	freopen("output.txt", "w", stdout);
// #endif

// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		int n, k;
// 		cin >> n >> k;
// 		vector<int> a(n);
// 		for (auto &it : a) cin >> it;
// 		map<int, int> cnt;
// 		int mx = 0;
// 		for (auto &it : a) {
// 			if (it % k == 0) continue;
// 			++cnt[k - it % k];
// 			mx = max(mx, cnt[k - it % k]);
// 		}
// 		long long ans = 0;
// 		for (pair<int, int> p : cnt) {
//             int key = p.first, value = p.second;
// 			if (value == mx) {
// 				ans = k * 1ll * (value - 1) + key + 1;
// 			}
// 		}
// 		cout << ans << endl;
// 	}
	
// 	return 0;
// }