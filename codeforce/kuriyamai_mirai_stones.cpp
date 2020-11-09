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
    cin>>n;
    arr.resize(0);
    vl ps_arr = {0};
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
        ll sum = *ps_arr.rbegin()+temp;
        ps_arr.push_back(sum);
    }

    sort(arr.begin(), arr.end());

    vl ps_arr_sort = {0};
    for(ll i=0; i<n; i++){
        ll sum = *ps_arr_sort.rbegin()+arr[i];
        ps_arr_sort.push_back(sum);
    }

    ll q;
    cin>>q;
    for(ll i=0; i<q; i++){
        ll type; cin>>type;
        ll a,b;
        cin>>a>>b; a--; b--;
        if (type == 1){
            cout << ps_arr[b+1] - ps_arr[a] << endl;
        } else {
            cout << ps_arr_sort[b+1] - ps_arr_sort[a] << endl;
        }
    }
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
