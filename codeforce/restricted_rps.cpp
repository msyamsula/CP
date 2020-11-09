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
map<char, ll> rules;
string bob;

void solve(){
    cin>>n;
    rules.clear();
    for(ll i=0; i<3; i++){
        ll temp; cin>>temp;
        if (i==0) rules['R'] = temp;
        else if (i==1) rules['P'] =temp;
        else if (i==2) rules['S']=temp;
    }
    cin>>bob;
    ll win = ceil(double(n)/2);
    map<char, ll> bob_rules;
    for(ll i=0; i<n; i++){
        char c = bob[i];
        bob_rules[c]++;
    }

    ll win_rock = min(rules['R'], bob_rules['S']);
    ll win_paper = min(rules['P'], bob_rules['R']);
    ll win_scissor = min(rules['S'], bob_rules['P']);
    if (win_rock+win_paper+win_scissor < win){
        cout << "NO" << endl;
        return;
    }

    string ans="";
    for(ll i=0; i<n; i++){
        if (bob[i] == 'R' && rules['P'] > 0){
            rules['P']--;
            ans+='P';
        } else if (bob[i] == 'P' && rules['S']>0){
            rules['S']--;
            ans+='S';
        } else if (bob[i] == 'S' && rules['R'] > 0){
            rules['R']--;
            ans+='R';
        } else {
            ans+='X';
        }
    }

    auto it = rules.begin();
    for(ll i=0; i<n; i++){
        if (ans[i]!='X') continue;
        while(it != rules.end() && it->second == 0) it++;
        ans[i] = it->first;
        it->second--;
    }

    cout << "YES" << endl;
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
