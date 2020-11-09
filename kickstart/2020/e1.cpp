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

ll n;
vl arr;

void solve(){
    arr.resize(0);
    vl dif;
    cin>>n;
    for(ll i=0; i<n; i++){
        ll temp;
        cin>>temp; 
        if (arr.empty()){
            // dif.push_back(temp);
        } else {
            dif.push_back(temp-(*arr.rbegin()));
        }
        arr.push_back(temp);
    }

    // showV(dif);
    n = dif.size();
    ll num = dif[0];
    ll same = 1;
    ll max_same = 1;
    for(ll i=1; i<n; i++){
        if (dif[i] == num){
            same++;
        } else {
            same = 1;
            num = dif[i];
        }
        max_same = max(max_same, same);
        // cout << i << ' ' << max_same << endl;
    }

    cout << max_same+1 << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
