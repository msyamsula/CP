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
string ans;
ll min_rest;

void search(ll i){
    if (i==arr.size()){
        // cout << ans << endl;
        ll rest = 0;
        for(char c : ans){
            if (c=='R') rest++;
        }
        min_rest = min(min_rest, rest);
        return;
    }

    ll type = arr[i];
    string choice = "";
    if (type == 1) choice.push_back('C');
    else if (type == 2) choice.push_back('G');
    else if (type == 3) choice += "CG";

    choice += 'R';
    char prev = 'R';
    if (i>0) prev = *ans.rbegin();

    bool work = 0;
    for(ll ii=0; ii<choice.size(); ii++){
        char c = choice[ii];
        if (c!='R'){
            if (c == prev) continue;
            work = 1;
            ans += c;
            search(i+1);
            ans.pop_back();
        }

        if (c == 'R'){
            if (!work){
                ans += c;
                search(i+1);
                ans.pop_back();
            }
        }
    }
}

void solve(){
    cin>>n;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    ans = "";
    min_rest = MAXLL;
    search(0);
    cout << min_rest << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
