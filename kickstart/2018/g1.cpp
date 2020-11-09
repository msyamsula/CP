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
#define var 200000
ll n;
vl arr;
vl cnt;

void solve(){
    arr.resize(0);
    cin>>n;
    cnt.resize(0); cnt.assign(var+1, 0);
    // map<ll, ll> mem;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
        cnt[temp]++;
        // mem[temp]++;
    }
    // cout << "tes" << endl;
    sort(arr.begin(), arr.end());
    // for(auto num : arr){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll ans = 0;
    for(ll i=0; i<n-1; i++){
        if (arr[i] == 0 || arr[i] == 1) continue;
        for(ll j=i+1; j<n; j++){
            ll one = arr[i], two = arr[j];
            ll target = one*two;
            //overflow
            if (target > var) continue;
            //zeros and ones
            if (target == two && target == one) continue;
            //single one
            if (target == two) continue;
            // cout << i << ' ' << j << ' ' << target << ' ' << cnt[target] << endl;
            ans += cnt[target];
        }
    }
    // cout << ans << endl;

    if(cnt[1] >= 3){
        ans += cnt[1]*(cnt[1]-2)*(cnt[1]-1)/6;
    }

    if(cnt[1] >= 1){
        ll ones = cnt[1];
        ll add = 0;
        for(ll i=2; i<=var; i++){
            if (cnt[i]>=2){
                add += cnt[i]-1;
            }
        }
        ans += ones*add;
    }

    if(cnt[0] >= 3){
        ans += cnt[0]*(cnt[0]-2)*(cnt[0]-1)/6;
    }

    if(cnt[0] >= 2){
        ll z_comb = cnt[0]*(cnt[0]-1)/2;
        ans += z_comb*(n-cnt[0]);
    }

    // if(cnt[0]>=1){
    //     ll zero = cnt[0];
    //     ll other = n-cnt[0];
    //     ll other_comb = other*(other-1)/2;
    //     ans += zero*other_comb;
    // }

    cout << ans << endl;
    


    // ll ans = 0;
    // for(auto it: mem){
    //     ll val = it.first;
    //     if (val == 0){
    //         if(mem[val] >= 3){
    //             ll temp = mem[val];
    //             ans += temp*(temp-1)*(temp-2)/6;
    //         }

    //         ll zero = (mem[val]-1)*mem[val]/2;
    //         ans += zero*(n-mem[val]);

    //         if (n-mem[val] >= 2){
    //             ll other = (n-mem[val])*(n-mem[val]-1)/2;
    //             ans += mem[val]*other;
    //         }

    //         continue;
    //     }
    //     mem[val]--;
        
    //     for(ll j=1; j*j<=val; j++){
    //         if (val%j == 0){
    //             ll one = j, two = val/j;
    //             if(mem.find(one) == mem.end() || mem.find(two) == mem.end()) continue;
    //             if(mem.at(one) <= 0 || mem.at(two) <= 0) continue;
    //             if (one == two && mem.at(one)>=2){
    //                 // for(auto it : mem){
    //                 //     cout << it.first << ' ' << it.second << endl;
    //                 // }
    //                 // cout << endl;
    //                 // cout << val << ' ' << one << ' ' << two << endl;
    //                 ans += mem.at(one)*(mem.at(two)-1)/2;
    //                 continue;
    //             }
    //             if (one != two){
    //                 // cout << val << ' ' << one << ' ' << two << endl;
    //                 ans += mem.at(one)*mem.at(two);
    //             }
    //         }
    //     }
    //     mem[val]++;
    // }

    // cout << ans << endl;

    

    // ll count = 0;
    // for(ll i=0; i<n-2; i++){
    //     for(ll j=i+1; j<n-1; j++){
    //         for(ll k=j+1; k<n; k++){
    //             if (arr[i]*arr[j]==arr[k]){
    //                 count++;
    //                 continue;
    //             }

    //             if (arr[i]*arr[k]==arr[j]){
    //                 count++;
    //                 continue;
    //             }

    //             if (arr[j]*arr[k]==arr[i]){
    //                 count++;
    //                 continue;
    //             }
    //         }
    //     }
    // }

    // cout << count << endl;
}


int main(){
    // sieve(1000000);
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    // vl ans = prime_factor(100);
    // cout << (1<<18) << endl;
    // for(ll num : ans){
    //     cout << num << endl;
    // }
    // cout << endl;

    return 0;
}
