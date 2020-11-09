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

ll L,S;
ll sz=26;
// string cur_string;
ll tot;
ll ans;

void search(ll start, ll len){
    cout << start << ' ' << len << endl;
    if (tot>S || len>L) return;
    if (len == L){
        if (tot != S) return;
        // cout << cur_string << endl;
        ans++;
        return;
    }

    for(ll i=start; i<sz; i++){
        tot += i+1;
        // cur_string += i+97;
        search(i+1, len+1);
        tot -= i+1;
        // cur_string.erase(cur_string.begin()+cur_string.size()-1, cur_string.end());
    }
}

void solve(){
    
    tot = 0;
    // cur_string = "";
    ans = 0;
    search(0,0);
    cout << ans << endl;
}

int main(){
    ll tc=1;
    while(cin>>L>>S){
        if(!L && !S) break;
        cout << "Case " << tc << ": ";
        solve();
        tc++;
    }

    return 0;
}
