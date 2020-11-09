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
typedef tuple<ll, ll, string> mydata;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)
#define GET(i, d) get<i>(d)

vector<mydata> arr;

bool comp(mydata a, mydata b){
    if (GET(0,a) != GET(0,b)){
        return GET(0,a) < GET(0,b);
    }

    return GET(1,a)<GET(1,b);
}

void solve(){
    ll n; cin>>n;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        string name; ll l,h; cin>>name>>l>>h;
        arr.push_back({l,h,name});
    }

    sort(arr.begin(), arr.end(), comp);

    // for(mydata temp : arr){
    //     cout << GET(0,temp) << ' ' << GET(1,temp) << ' ' << GET(2,temp) << endl;
    // }
    // cout << endl;

    ll q; cin>>q;
    for(ll i=0; i<q; i++){
        ll val; cin>>val;
        // vector<bool> pass(n,0);
        ll idx=0;
        ll count=0;
        string ans = "UNDETERMINED";
        for(mydata temp : arr){
            if (GET(0,temp)<=val && val<=GET(1,temp)){
                // pass[idx]=1;
                count++;
                ans = GET(2,temp);
            }

            if (count > 1){
                // cout << "UNDETERMINED" << endl;
                ans = "UNDETERMINED";
                break;
            }
            idx++;
        }
        cout << ans << endl;
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if(i!=0) cout << endl;
        solve();
    }

    return 0;
}
