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

map<string, ll> memo;

ll trim(string s){
    if (memo.find(s) != memo.end()) return memo[s];
    // cout << s << endl;
    vs block;
    for(ll i=0; i<s.size(); i++){
        string temp;
        ll j;
        for(j=i; j<s.size(); j++){
            if (s[j]==s[i]) temp += s[j];
            else break;
        }
        i=j-1;
        block.push_back(temp);
    }

    vl ps; ps.assign(block.size()+1,0);
    for(ll i=0; i<ps.size()-1; i++){
        ps[i+1] = ps[i] + block[i].size();
    }
    
    // cout << s << ' ';
    // cout << block.size() << endl;
    if (block.size()==1 && block[0].size()==1) return memo[s]=1;
    else if (block.size() ==1 && block[0].size()>1) return memo[s]=0;

    ll ans = s.size();
    for(ll i=0; i<ps.size()-1; i++){
        ll start = ps[i], end = ps[i+1], sz = end-start;
        if (sz < 2) continue;
        string stemp = s;
        stemp.erase(start,sz);
        // cout << c << endl;
        ans = min(ans, trim(stemp));
    }

    return memo[s]=ans;
}

void solve(){
    string s; cin>>s;
    if(trim(s)>0){
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    // cout << trim(s) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
