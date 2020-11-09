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

ll n, k;
string s;
set<char> keyboard;

void solve(){
    cin>>n>>k;
    cin>>s;
    keyboard.clear();
    for(ll i=0; i<k; i++){
        char temp; cin>>temp;
        keyboard.insert(temp);
    }

    vl block;
    ll len = 0;
    for(ll i=0; i<n+1; i++){
        if (i==n){
            block.push_back(len);
            break;
        }
        char c = s[i];
        if (keyboard.find(c) == keyboard.end()){
            block.push_back(len);
            len = 0;
        } else {
            len++;
        }
    }

    ll tot = 0;
    for(ll num : block){
        ll temp = num*(num+1); temp/=2;
        tot += temp;
        // cout << num << ' ';
    }
    // cout << endl;

    cout << tot << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
