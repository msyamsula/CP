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

ll findMax(vl a){
    ll n = a.size();
    if (n == 1) return a[0];
    if (n == 0) return -MAXLL;

    ll neg_cnt = 0;
    vl pre_sum = {1};
    for(ll i=0; i<n; i++){
        if (a[i] < 0) neg_cnt++;
        ll temp = *pre_sum.rbegin()*a[i];
        pre_sum.push_back(temp);
    }

    if ( (neg_cnt&1) == 0) return pre_sum[n];

    showV(pre_sum);

    ll ans = -MAXLL;
    for(ll i=0; i<n; i++){
        cout << "i = " << i << ", ans = " << ans << endl;
        if (a[i]<0){
            ans = max(ans, pre_sum[i]/pre_sum[0]);
            cout << ans;
            ans = max(ans, pre_sum[n]/pre_sum[i+1]);
            cout << ", " << ans << endl;
        }
    }

    return ans;
}

vl arr;

void solve(){
    ll temp;
    while(cin>>temp){
        if(temp == -999999) break;
        arr.push_back(temp);
    }
    bool contain_zero = 0;
    vvl segment;
    vl cur_arr;
    ll n = arr.size();
    for(ll i=0; i<n; i++){

        if (arr[i] == 0){
            segment.push_back(cur_arr);
            cur_arr.resize(0);
            contain_zero = 1;
        } else {
            cur_arr.push_back(arr[i]);
        }

        if (i == n-1 && arr[i]!=0){
            segment.push_back(cur_arr);
        }
    }

    showVV(segment);

    n=segment.size();
    ll maxprod = -MAXLL;
    for(ll i=0; i<n; i++){
        maxprod = max( maxprod, findMax(segment[i]) );
        
    }

    // cout << "ans: ";
    maxprod = maxprod < 0 && contain_zero ? 0 : maxprod;
    maxprod = maxprod == -MAXLL ? 0 : maxprod;
    cout << maxprod << endl;
}

int main(){
    ll num;
    while(cin>>num){
        arr.resize(0);
        arr.push_back(num);
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
