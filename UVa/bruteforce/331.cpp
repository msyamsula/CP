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
vs swapmap;
ll ans;

void search(){
    bool recurse = 0;
    for(ll i=0; i<n-1; i++){
        if (arr[i] <= arr[i+1]) continue;
        ll temp = arr[i]; arr[i]=arr[i+1]; arr[i+1]=temp;
        string s = to_string(i) + " swap " + to_string(i+1);
        swapmap.push_back(s);
        recurse = 1;
        search();
        swapmap.pop_back();
        temp = arr[i]; arr[i]=arr[i+1]; arr[i+1]=temp;
    }

    if (!recurse){
        if (swapmap.size() == 0) return;
        ans++;
        // for(string s : swapmap){
        //     cout << s << endl;
        // }
        // cout << endl;
    }
}

void solve(ll tc){
    arr.resize(0);
    swapmap.resize(0);
    ans = 0;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    search();

    cout << "There are " << ans << " swap maps for input data set " << tc << '.' << endl;
}

int main(){
    ll tc=1;
    while(cin>>n){
        if (!n) break;
        solve(tc);
        tc++;
        // cout << endl;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
