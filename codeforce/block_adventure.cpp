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

ll n,m,k;
vl blocks;

void solve(){
    // cout << "test" << endl;
    cin>>n>>m>>k;
    blocks.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        blocks.push_back(temp);
    }
    // cout << "bag: " << m << endl;
    // cout << "k: " << k << endl;
    // cout << "blocks: ";
    // for(ll num : blocks){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll bag = m;
    for(ll i=0; i<n-1; i++){
        if (blocks[i+1]-blocks[i] == k){
            continue;
        } else if (blocks[i+1]-blocks[i] > k && bag>0){
            ll min_distance = blocks[i+1]-blocks[i]-k;
            if (min_distance > bag){
                cout << "NO" << endl;
                // cout << "stop at index: " << i << endl;
                return;
            }
            bag -= min_distance;
        } else if (blocks[i+1]-blocks[i] < k){
            ll take = blocks[i]-blocks[i+1]+k;
            take = min(take, blocks[i]);
            // if (take > blocks[i]){
            //     cout << "NO" << endl;
            //     return;
            // }
            bag += take;
        } else {
            cout << "NO" << endl;
            // cout << "stop at index: " << i << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
        // cout << endl;
    }

    return 0;
}
