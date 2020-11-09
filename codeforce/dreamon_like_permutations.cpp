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

ll n;
vl arr;

void solve(){
    arr.resize(0);
    cin>>n;
    vl flags;
    vl ps_flags; ps_flags.push_back(0);
    vl ps_arr; ps_arr.push_back(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        if (i==0) flags.push_back(1);
        else {
            if (*arr.rbegin() == temp) flags.push_back(0);
            else flags.push_back(1);
        }
        arr.push_back(temp);

        ll sum = *ps_flags.rbegin()+(*flags.rbegin());
        ps_flags.push_back(sum);
        ll sum_arr = *ps_arr.rbegin() + (*arr.rbegin());
        ps_arr.push_back(sum_arr);
    }

    // cout << "arr: ";
    // for(ll num : arr){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // cout << "flags: ";
    // for(ll num : flags){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // cout << "ps_flags: ";
    // for(ll num : ps_flags){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // cout << "ps_arr: ";
    // for(ll num : ps_arr){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll ans = 0;

    vvl index;
    for(ll i=0; i<n-1; i++){
        ll l_flag = ps_flags[i+1]-ps_flags[0];
        ll l_sum = ps_arr[i+1]-ps_arr[0];

        ll l_target = i+1;
        ll sum_l_target = (l_target+1)*l_target; sum_l_target/=2;

        ll r_flag = ps_flags[n]-ps_flags[i+1];
        ll r_sum = ps_arr[n] - ps_arr[i+1];

        ll r_target = n-(l_target);
        ll sum_r_target = (r_target+1)*r_target; sum_r_target/=2;
        if (l_target == l_flag && l_sum == sum_l_target){
            if (r_flag == r_target && r_sum == sum_r_target){
                // cout << i << ": " << l_flag << ' ' << l_sum << ' ' << r_flag << ' ' << r_sum << endl;
                // cout << l_flag << ' ' << r_flag << endl;
                index.push_back({l_flag, n-l_flag});
                ans++;
            }
        }
    }

    cout << ans << endl;
    for(vl a : index){
        for(ll i=0; i<2; i++){
            if(i!=0) cout << ' ';
            cout << a[i];
        }
        cout << endl;
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
