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

void solve(){
    cin>>n;
    ll x = 0;
    for(ll i=0; i<n; i++){
        string temp; cin>>temp;
        for(char c : temp){
            if (c == '+'){
                x++;
                break;
            } else if (c== '-'){
                x--;
                break;
            }
            else continue;
        }
    }

    cout << x << endl;
}

int main(){
    // int tc; cin>>tc;
    ll tc=1;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
