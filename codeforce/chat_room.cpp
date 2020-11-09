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
void showV(vl temp){
    for(ll t : temp){
        cout << t << ' ';
    }
    cout << endl;
}

void showVV(vvl temp){
    for (vl t : temp){
        for(ll t1 : t){
            cout << t1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

string s;

void solve(){
    cin>>s;
    string target = "hello";

    ll i=0,j=0;
    while(i<target.size() && j<s.size()){
        while(s[j] != target[i] && j < s.size()){
            j++;
        }
        if (j>=s.size()) break;
        // cout << "same at i: " << i << ", " << target[i] << " j: " << j << ", " << s[j] << endl;
        i++; j++;
    }

    if (i == target.size()){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main(){
        solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
