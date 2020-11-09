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

ll n,b;
vl arr;

void solve(){
    cin>>n>>b;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }
    ll odd=0, even=0;
    vl cut;
    for(ll i=0; i<n; i++){
        // cout << i << endl;
        if (odd>0 && even>0 && odd == even){
            ll price = abs(arr[i]-arr[i-1]);
            cut.push_back(price);
            // cout << "cut between" << i-1 << ", " << i << endl;
        }

        if (arr[i]%2==0) even++;
        else odd++;
    }

    sort(cut.begin(), cut.end());
    if (cut.size()==0){
        cout << 0 << endl;
        return;
    }

    // cout << "cut: ";
    // for(ll num : cut){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll cost = 0;
    ll tot = 0, i=0;
    while(cost<b && i<cut.size()){
        cost += cut[i];
        if (cost >b) break;
        // cout << cost << ' ' << b << endl;
        tot++;
        i++;        
    }

    cout << tot << endl;
    // for(ll i=1; i<=100; i++){
    //     cout << i << ' ';
    // }
    // cout << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
