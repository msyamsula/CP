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

ll num;
vl arr, lis, dp;
deque<ll> state;

void backtrack(ll idx){
    state.push_front(arr[idx]);
    for(ll i=idx; i>=0; i--){
        if (dp[i]+1 == dp[idx] && arr[i] < arr[idx]){
            return backtrack(i);
        }
    }
}

// void solve(){
//     ll n = arr.size();
//     dp.resize(0); dp.assign(n, 1);
//     state.resize(0);
//     for(ll i=1; i<n; i++){
//         for(ll j=0; j<i; j++){
//             if (arr[j]<arr[i]){
//                 dp[i] = max(dp[i], dp[j]+1);
//             }
//         }
//     }

//     ll idx = 0;
//     ll len = 0;
//     for(ll i=0; i<n; i++){
//         if (dp[i] >= len){
//             len = dp[i];
//             idx = i;
//         }
//     }

//     backtrack(idx);
//     cout << len << endl;
//     cout << '-' << endl;
//     for(ll i=0; i<state.size(); i++){
//         cout << state[i] << endl;
//     }
// }

void solve(){
    lis.resize(0);
    dp.resize(0);
    ll n = arr.size();
    // for(ll num : arr){
    //     cout << num << ' ';
    // }
    // cout << endl;
    dp.assign(n, 0);
    for(ll i=0; i<n; i++){
        ll number = arr[i];
        if (lis.size() == 0){
            lis.push_back(number);
            dp[i] = 1;
            continue;
        }
        auto it = upper_bound(lis.begin(), lis.end(), number);
        auto it_temp = it;
        if (it == lis.begin()){
            *it = number;
            dp[i] = 1;
            continue;
        }
        // cout << "i: " << i << endl;
        it--;
        if (*it == number){
            dp[i] = distance(lis.begin(), it)+1;
        } else if (it_temp == lis.end()){
            // cout << "distance: " << distance(lis.begin(), it_temp) << endl;
            lis.insert(it_temp, number);
            dp[i] = lis.size();
        } else {
            *it_temp = number;
            dp[i] = distance(lis.begin(), it_temp)+1;
        }

        // if (it == lis.end()){
        //     lis.insert(it, number);
        //     dp[i] = 1;
        // } else {
        // }
        // for(ll num : lis){
        //     cout << num << ' ';
        // }
        // cout << endl;
    }

    // for(ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll len = lis.size();
    ll idx;
    for(ll i=n-1; i>=0; i--){
        if (dp[i] == len){
            idx = i; break;
        }
    }
    // cout << "idx: " << idx << endl;
    state.resize(0);
    backtrack(idx);
    // state.push_front(lis[len-1]);
    // if (len > 1) backtrack(n-1, lis[len-2], lis[len-1]);
    cout << len << endl;
    cout << "-" << endl;
    for(ll num : state){
        cout << num << endl;
    }
}

int main(){
    while(cin>>num){
        arr.push_back(num);
    }

    solve();

    return 0;
}
