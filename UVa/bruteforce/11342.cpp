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

ll K;
vvl combinations;
vl cur_combinations;
ll sum;

void search(ll idx, ll start, ll end){
    // if (sum > K) return;
    // cout << idx << ' ' << sum << endl;
    // cout << "array : ";
    // for (ll num : cur_combinations){
    //     cout << num << ' '; 
    // }
    // cout << endl;
    if (idx == 2){
        ll target = K - sum;
        double sqrt_target = pow(target, 0.5);
        if ( sqrt_target == floor(sqrt_target)){
            // cout << sqrt_target << endl;
            if ( (ll)sqrt_target < start ) return;
            cur_combinations.push_back((ll)sqrt_target);
            combinations.push_back(cur_combinations);
            // cout << "accepted : ";
            // for(ll num : cur_combinations){
            //     cout << num << ' ';
            // }
            // cout << endl;
            cur_combinations.pop_back();
        }
        return;
    }


    for(ll i=start; i<=end; i++){
        sum += i*i;
        cur_combinations.push_back(i);
        search(idx+1, i, end);
        cur_combinations.pop_back();
        sum -= i*i;
    }
}


// void solve(){
//     cin>>K;
//     combinations.resize(0);
//     cur_combinations.resize(0);
//     sum = 0;
//     ll k = ceil(double(K)/3);
//     ll sqrt_k = ceil(pow(k, 0.5));
//     search(0, 0, sqrt_k);
//     ll n = combinations.size();
//     if (n == 0){
//         cout << -1 << endl;
//         return;
//     }

//     n = combinations[0].size();
//     for(ll i=0; i<n; i++){
//         cout << combinations[0][i] << " \n"[i==n-1];
//     }
// }

void solve(){
    cin>>K;
    ll k = ceil(double(K));
    ll sqrt_k = ceil(pow(k, 0.5));
    for (ll i=0; i<=sqrt_k; i++){
        for(ll j=i; j<=sqrt_k; j++){
            ll sum = i*i + j*j;
            if (sum > K) break;
            ll remaining = K-sum;
            double sqrt_remaining = pow(remaining, 0.5);
            if (ceil(sqrt_remaining) == sqrt_remaining){
                vl temp = {i,j,(ll)sqrt_remaining};
                sort(temp.begin(), temp.end());
                cout << temp[0] << ' ' << temp[1] << ' ' << temp[2] << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
