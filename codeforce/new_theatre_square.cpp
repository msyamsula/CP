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

ll n,m,one,two;
vs grid;

void solve(){
    cin>>n>>m>>one>>two;
    grid.resize(0);
    for(ll i=0; i<n; i++){
        string temp; cin>>temp;
        grid.push_back(temp);
    }

    double bpt_one = (double)one;
    double bpt_two = (double)two/2;

    if (bpt_one <= bpt_two){
        ll cnt = 0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if (grid[i][j] == '.') cnt++;
            }
        }

        cout << one*cnt << endl;
        return;
    }

    ll ans = 0;
    vvl paved; paved.assign(n, vl(m,0));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if (paved[i][j] || grid[i][j] == '*') continue;
            if ( (j+1<m) && grid[i][j] == '.' && grid[i][j+1] == '.'){
                ans += two;
                paved[i][j] = paved[i][j+1] = 1;
                continue;
            }
            ans += one;
            paved[i][j] = 1;
        }
    }

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
