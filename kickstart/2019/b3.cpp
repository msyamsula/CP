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

ll n,s;
vl arr;

void solve(){
    cin>>n>>s;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }


    ll ans = 1;
    queue<ll> q;
    map<ll, ll> mem;
    for(ll i=0; i<n; i++){
        mem[arr[i]]++;
        if (mem[arr[i]] <= s){
            q.push(arr[i]);
            ans = max(ans, (ll)q.size());
            continue;
        }

        while(q.front()!=arr[i]){
            mem.erase(q.front());
            q.pop();
        }
    // cout << "tes" << endl;
        q.pop();
        mem[arr[i]]--;
        q.push(arr[i]);
        ans = max(ans, (ll)q.size());
    }

    mem.clear();
    for(ll num : arr){
        mem[num]++;
    }

    ll take_all = 0;
    for(pair<ll, ll> temp : mem){
        if (temp.second <= s) take_all += temp.second;
    }

    cout << max(take_all, ans) << endl;
}

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    vvl arr(100000, vl(100000, 0));

    return 0;
}
