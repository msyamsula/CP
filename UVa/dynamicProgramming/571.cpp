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

ll ca,cb,n;
vector<vector<pair<ll, ll>>> dp;
vs ans;

void backtrack(pair<ll,ll> coor){
    ll i = coor.first, j = coor.second;
    // cout << i << ' ' << j << endl;
    pair<ll, ll> pcoor = dp[i][j];
    ll pi = pcoor.first, pj = pcoor.second;
    if (i==pi && j==pj) return;
    //filla
    if (j==pj && pi<i && i==ca) ans.push_back("fill A");
    //fillb
    if (pj<j && pi==i && j==cb) ans.push_back("fill B");
    //emptya
    if (pj==j && pi!=0 && i==0) ans.push_back("empty A");
    //emptyb
    if (pj!=0 && j==0 && i==pi) ans.push_back("empty B");
    //ab
    if (pj<j && i<pi) ans.push_back("pour A B");
    //ba
    if (pj>j && i>pi) ans.push_back("pour B A");
    backtrack(pcoor);
}

void solve(){
    ans.push_back("success");
    dp.resize(0); dp.assign(ca+1, vector<pair<ll, ll>>(cb+1, {-1,-1}));
    // while(1){
    //     ll i=dp.size()-1;
    //     vl newrow; newrow.assign(cb+1, -1);
    //     for(ll j=0; j<=cb; j++){
    //         //filla
    //         dp[ca][j]=i*(n+1)+j);
    //         //fillb
    //         cout << i << ' ' << j << ' ' << dp[i][cb] << endl;
    //         dp[i][cb]=max(dp[i][cb], i*10+j);
    //         //emptya
    //         dp[0][j]=max(dp[0][j], i*10+j);
    //         //emptyb
    //         dp[i][0]=max(dp[i][0], i*10+j);
    //         //ab
    //         ll tb = cb-j;
    //         ll fa = i;
    //         ll trf = min(tb,fa);
    //         dp[i-trf][j+trf]=max(dp[i-trf][j+trf], i*10+j);
    //         //ba
    //         ll fb = j;
    //         ll ta = ca-i;
    //         trf = min(ta,fb);
    //         dp[i+trf][j-trf]=max(dp[i+trf][j-trf], i*10+j);
    //     }
    // }
    dp[0][0]={0,0};
    queue<pair<ll,ll>> q;
    q.push(dp[0][0]);

    pair<ll,ll> bcoor;
    while(!q.empty()){
        ll i=q.front().first, j=q.front().second; q.pop();
        // cout << i << ' ' << j << endl;
        if (j==n) {
            bcoor={i,j};
            break;
        }
        if (dp[ca][j] == make_pair(-1ll,-1ll)){
            dp[ca][j]={i,j};
            q.push({ca,j});
        }
        //fillb
        if (dp[i][cb] == make_pair(-1ll,-1ll)){
            dp[i][cb]={i,j};
            q.push({i,cb});
        }
        //emptya
        // dp[0][j]=max(dp[0][j], i*10+j);
        if (dp[0][j] == make_pair(-1ll,-1ll)){
            dp[0][j]={i,j};
            q.push({0,j});
        }
        //emptyb
        // dp[i][0]=max(dp[i][0], i*10+j);
        if (dp[i][0] == make_pair(-1ll,-1ll)){
            dp[i][0]={i,j};
            q.push({i,0});
        }
        //ab
        ll tb = cb-j;
        ll fa = i;
        ll trf = min(tb,fa);
        if (dp[i-trf][j+trf] == make_pair(-1ll,-1ll)){
            dp[i-trf][j+trf]={i,j};
            q.push({i-trf,j+trf});
        }
        //ba
        ll fb = j;
        ll ta = ca-i;
        trf = min(ta,fb);
        if (dp[i+trf][j-trf] == make_pair(-1ll,-1ll)){
            dp[i+trf][j-trf]={i,j};
            q.push({i+trf,j-trf});
        }

    }

    // cout << n << endl;
    // for(vector<pair<ll, ll>> temp : dp){
    //     for(pair<ll, ll> num : temp){
    //         cout << num.first << ',' << num.second << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(ll i=0; i<=ca; i++){
    //     if (dp[i][n] != make_pair(-1ll,-1ll)){
    //         // cout << "start " << i << ' ' << n << endl;
    //         backtrack({i,n});
    //         break;
    //     }
    // }
    backtrack(bcoor);

    while(!ans.empty()){
        cout << ans[ans.size()-1] << endl;
        ans.pop_back();
    }
}


int main(){
    // int tc; cin>>tc;
    while(cin>>ca>>cb>>n){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
